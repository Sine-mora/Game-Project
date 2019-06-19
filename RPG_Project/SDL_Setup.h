#pragma once

class Setup 
{
public:
	Setup(bool* quit, int ScreenWidth, int ScreenHeight);
	~Setup();

	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();

	void Begin();
	void End();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;

};