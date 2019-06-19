#include "Header.h"
#include "SDL_Setup.h"

Setup::Setup(bool* quit, int ScreenWidth, int ScreenHeight)
{
	SDL_Init(SDL_INIT_VIDEO);

	window = nullptr;
	window = SDL_CreateWindow("The new prince",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN );

	if (window == nullptr)
	{
		std::cerr << "Failed to create window!\n";
		*quit = true;
	}

	renderer = nullptr;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	mainEvent = new SDL_Event();
}

Setup::~Setup()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}

SDL_Renderer* Setup::GetRenderer() 
{
	return renderer;
}

SDL_Event* Setup::GetMainEvent()
{
	return mainEvent;
}

void Setup::Begin()
{
	SDL_PollEvent(mainEvent);
	SDL_RenderClear(renderer);
}

void Setup::End()
{
	SDL_RenderPresent(renderer);
}