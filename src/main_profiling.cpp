#ifndef __GNUC__
#pragma region declarations
#endif
#include <glad/glad.h>
#include <omp.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include "lib/myMath/Vec2.hpp"
#include "lib/myMath/utils.hpp"
#include "resources/model/Flock.hpp"
#include "resources/graphics/glx.hpp"
#include "resources/graphics/graphics.hpp"
#include "resources/graphics/GraphicalManager.hpp"
#include "resources/graphics/oglTypes.hpp"
#include "resources/controller/flock_generator.hpp"
#include "utils/Timer.hpp"
#include "tbb/tbb.h"
#include <tbb/task_arena.h>
#ifndef __GNUC__
#pragma endregion
#endif

Flock* MAIN_pFLOCK = nullptr;
std::vector<Agent*> mainFlock;


void nloopturns_omp(Flock* MAIN_pFLOCK, int n, int nb_threads) {
    long int t = 0;
    
    omp_set_dynamic(0);     // Explicitly disable dynamic teams
    omp_set_num_threads(nb_threads); // Use 4 threads for all consecutive parallel regions
    
    do {
        //std::cout << "Tour " << t << '\n';
        #pragma omp parallel for shared(MAIN_pFLOCK) 
        for (int i = 0; i < (*MAIN_pFLOCK).getPopSize(); ++i) {
            Agent* bird = (*MAIN_pFLOCK)[i];
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
    } while (t <= n);
}

void nloopturns_tbb(Flock* MAIN_pFLOCK, int n, int nb_threads) {
    long int t = 0;

    tbb::task_scheduler_init def_init; // Use the default number of threads.
    tbb::task_arena arena(nb_threads);        // No more than 2 threads in this arena.

    do {
        arena.execute([&] {
            tbb::parallel_for(0, (*MAIN_pFLOCK).getPopSize(),
                [&](int r)
            {
                Agent* bird = (*MAIN_pFLOCK).getAgent(r);
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
    } while (t <= n);

}

int main() {
    int size = 2048;
    mainFlock.reserve(size);


    Flock flock = generate_parrot_flock(size);


    MAIN_pFLOCK = &flock;
    Timer timer;
    std::cout << "Beginning OMP" << std::endl;
    {
        Sentry sentry(timer, "OMP 100 loops, 1 thread");
        nloopturns_omp(MAIN_pFLOCK, 100, 1);
    }
    {
        Sentry sentry(timer, "OMP 100 loops, 2 thread");
        nloopturns_omp(MAIN_pFLOCK, 100, 2);
    }
    {
        Sentry sentry(timer, "OMP 100 loops, 4 thread");
        nloopturns_omp(MAIN_pFLOCK, 100, 4);
    }
    {
        Sentry sentry(timer, "OMP 100 loops, 8 thread");
        nloopturns_omp(MAIN_pFLOCK, 100, 8);
    }
    {
        Sentry sentry(timer, "OMP 100 loops, 12 thread");
        nloopturns_omp(MAIN_pFLOCK, 100, 12);
    }
    {
        Sentry sentry(timer, "OMP 100 loops, 16 thread");
        nloopturns_omp(MAIN_pFLOCK, 100, 16);
    }
    {
        Sentry sentry(timer, "OMP 100 loops, 24 thread");
        nloopturns_omp(MAIN_pFLOCK, 100, 24);
    }


    std::cout << "Beginning TBB" << std::endl;
    {
        Sentry sentry(timer, "TBB 100 loops, 1 thread");
        nloopturns_tbb(MAIN_pFLOCK, 100, 1);
    }
    std::cout << "Second TBB" << std::endl;
    {
        Sentry sentry(timer, "TBB 100 loops, 2 thread");
        nloopturns_tbb(MAIN_pFLOCK, 100, 2);
    }
    std::cout << "Third TBB" << std::endl;
    {
        Sentry sentry(timer, "TBB 100 loops, 4 thread");
        nloopturns_tbb(MAIN_pFLOCK, 100, 4);
    }
    std::cout << "4th TBB" << std::endl;
    {
        Sentry sentry(timer, "TBB 100 loops, 8 thread");
        nloopturns_tbb(MAIN_pFLOCK, 100, 8);
    }

    std::cout << "5th TBB" << std::endl;
    {
        Sentry sentry(timer, "TBB 100 loops, 12 thread");
        nloopturns_tbb(MAIN_pFLOCK, 100, 12);
    }

    std::cout << "6th TBB" << std::endl;
    {
        Sentry sentry(timer, "TBB 100 loops, 16 thread");
        nloopturns_tbb(MAIN_pFLOCK, 100, 16);
    }

    std::cout << "8th TBB" << std::endl;
    {
        Sentry sentry(timer, "TBB 100 loops, 24 thread");
        nloopturns_tbb(MAIN_pFLOCK, 100, 24);
    }

    timer.printInfo();
    return 0;
}

