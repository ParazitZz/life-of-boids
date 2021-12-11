#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include "lib/myMath/Vec2.hpp"
#include "lib/myMath/utils.hpp"
#include "resources/model/Flock.hpp"
#include "resources/graphics/glx.hpp"
#include "resources/graphics/graphics.hpp"
#include "resources/graphics/GraphicalManager.hpp"
#include "resources/graphics/oglTypes.hpp"
#include "resources/controller/flock_generator.hpp"


Flock* MAIN_pFLOCK = nullptr;

int main(int argc, char* argv[]) {

	try
	{
		Flock flock = generate_flock_with_args(argc, argv);

<<<<<<< Updated upstream
		bool fullScreen = false;
		GraphicalManager GM{ Color::BlueGrey, fullScreen };
		MAIN_pFLOCK = &flock;
=======
    //Flock flock = generate_dove_flock(size);
    //Flock flock = generate_parrot_flock(size);
    //Flock flock = generate_duck_flock(size);
    //Flock flock = create_bird_flock(size, Color::Blue, 3, 50, 180, Vec2{ 0,0 }, Vec2{ 1,1 });
    Flock flock = generate_fully_random_bird_flock();
    //Flock flock = generate_ant_flock(size);
    //Flock flock = generate_fly_flock(size);
>>>>>>> Stashed changes

		float t = 0;
		bool shouldClose = false;
		do {
			shouldClose = GM.mainLoop();
			++t;
		} while (!shouldClose);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;

}
