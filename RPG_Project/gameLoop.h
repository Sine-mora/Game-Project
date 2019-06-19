#pragma once
#include "SDL_Setup.h"
#include "Game_Sprites.h"

class Loop
{
public:
	Loop(int passed_ScreenWidth, int passed_ScreenHeight);
	~Loop();

	void GameLoop();


private:
	int ScreenWidth;
	int ScreenHeight;

	bool quit;

	Setup* setup;

	Sprite* main_Menu_Background;

	Sprite* main_MBtn;
	Sprite* main_MBtn_H;

	SDL_Rect passed_SrcR;
	SDL_Rect passed_DestR;

	Sprite* tileset;

	Sprite* hero;

	int MouseX;
	int MouseY;

};