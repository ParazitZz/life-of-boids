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

#define LOOP_SIZE 80
#define FLOCK_SIZE_START 5000
#define FLOCK_SIZE_END 5011

int main() {
    Timer timer;

    omp_set_num_threads(4);
    int nb_th = omp_get_num_threads();
    std::cout << "NB_THREAD : " << nb_th << std::endl;

    for(int size = FLOCK_SIZE_START; size < FLOCK_SIZE_END; size += 500){

        if(size > 2000){
            size += 500;
        }
        std::string str(std::to_string(size) + "_");

        Flock flock = generate_parrot_flock(size);

        std::cout << "FLOCK SIZE=" << size << "\nLOOP_SIZE=" << LOOP_SIZE << std::endl;


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
                #pragma omp parallel for shared(MAIN_pFLOCK) num_threads(4)
                for (int i = 0; i < (*MAIN_pFLOCK).getPopSize(); ++i){
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
                ++t;
            } while (t <= LOOP_SIZE);
        }
    }

        timer.printInfo();

    return 0;
}

