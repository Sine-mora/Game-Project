#include "Header.h"
#include "gameLoop.h"


int main(int argc, char *argv []) {

	//SDL_Init(SDL_INIT_VIDEO);

	Loop* loop = new Loop(800,600);

	loop->GameLoop();


	delete loop;

	SDL_Quit();
	IMG_Quit();

	return 0;
}
