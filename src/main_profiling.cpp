#ifndef __GNUC__
#pragma region declarations
#endif
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <omp.h>
#include "lib/myMath/Vec2.hpp"
#include "lib/myMath/utils.hpp"
#include "resources/model/Flock.hpp"
#include "resources/graphics/glx.hpp"
#include "resources/graphics/graphics.hpp"
#include "resources/graphics/GraphicalManager.hpp"
#include "resources/graphics/oglTypes.hpp"
#include "resources/controller/flock_generator.hpp"
#include "lib/myTimer/Timer.hpp"
#include "tbb/tbb.h"
#include <string>

#ifndef __GNUC__
#pragma endregion
#endif

Flock* MAIN_pFLOCK = nullptr;
std::vector<Agent*> mainFlock;

#define LOOP_SIZE 1
#define FLOCK_SIZE 5000
#define NB_THREADS 1

int main() {
    Timer timer;



    std::string str(std::to_string(FLOCK_SIZE) + "_");

    Flock flock = generate_parrot_flock(FLOCK_SIZE);

    std::cout << "FLOCK SIZE=" << FLOCK_SIZE << "\nLOOP_SIZE=" << LOOP_SIZE << std::endl;


    MAIN_pFLOCK = &flock;

    // {
    //     Sentry sentry(timer,str+"Seq");
    //     long int t = 0;
    //     do {
    //         // std::cout << "Tour " << t << '\n';
    //         for (auto& bird : *MAIN_pFLOCK) {
    //             std::tuple<std::vector<Agent*>, std::vector<Agent*>> allNeighbors =
    //                 (*MAIN_pFLOCK).computeNeighbors(*bird); //this costs performance
    //             std::vector<Agent*> bVec = std::get<0>(allNeighbors);
    //             std::vector<Agent*> eVec = std::get<1>(allNeighbors);

    //             (*bird).computeLaws(bVec, eVec);
    //             (*bird).prepareMove();
    //             (*bird).setNextPosition(keepPositionInScreen((*bird).getNextPosition(), 800, 800));
    //             (*bird).move();
    //         }
    //         ++t;
    //     } while (t <= LOOP_SIZE);
    // }

    {
        Sentry sentry(timer, str+"OMP");
        long int t = 0;
        do {
            #pragma omp parallel for shared(MAIN_pFLOCK) num_threads(NB_THREADS)
            for (int i = 0; i < (*MAIN_pFLOCK).getPopSize(); ++i){
                // std::cout << omp_get_num_threads() << std::endl;

                Agent *bird = (*MAIN_pFLOCK)[i];
                std::tuple<std::vector<Agent*>, std::vector<Agent*>> allNeighbors =
                    (*MAIN_pFLOCK).computeNeighbors(*bird); //this costs performance
                std::vector<Agent*> bVec = std::get<0>(allNeighbors);
                std::vector<Agent*> eVec = std::get<1>(allNeighbors);

                (*bird).computeLaws(bVec, eVec);
                (*bird).prepareMove();
                (*bird).setNextPosition(keepPositionInScreen((*bird).getNextPosition(), 800, 800));
                (*bird).move();
            }
            ++t;
        } while (t <= LOOP_SIZE);
    }


    {
        Sentry sentry(timer,str+"TBB");
        long int t = 0;
        do {
            // tbb::task_scheduler_init(NB_THREADS);
            tbb::task_arena arena(NB_THREADS);
            
            arena.execute([]{
                tbb::parallel_for(size_t(0), (size_t)(*MAIN_pFLOCK).getPopSize(),
                        [&](size_t i){
                    Agent *bird = (*MAIN_pFLOCK)[i];
                    std::tuple<std::vector<Agent*>, std::vector<Agent*>> allNeighbors =
                        (*MAIN_pFLOCK).computeNeighbors(*bird); //this costs performance
                    std::vector<Agent*> bVec = std::get<0>(allNeighbors);
                    std::vector<Agent*> eVec = std::get<1>(allNeighbors);

                    (*bird).computeLaws(bVec, eVec);
                    (*bird).prepareMove();
                    (*bird).setNextPosition(keepPositionInScreen((*bird).getNextPosition(), 800, 800));
                    (*bird).move();            
                });
            });


            ++t;
        } while (t <= LOOP_SIZE);
    }


        timer.printInfo();

    return 0;
}

