#pragma once
#include "SDL_Setup.h"
#include "Game_Sprites.h"
#include "MainMenuButton.h"

enum EGameState
{
	eMainMenu,
	ePlayGame,
};
class Loop
{
public:
	Loop(int passed_ScreenWidth, int passed_ScreenHeight);
	~Loop();

	void GameLoop();

	void OnUpdate(SDL_Event* ptrEvent);
	void OnDraw();


private:
	int ScreenWidth;
	int ScreenHeight;

	EGameState m_eGameState;

	bool quit;

	Setup* setup;

	MainMenuButton m_btnNewGame;

	Sprite* main_Menu_Background;
	Sprite* main_MBtn;
	Sprite* main_MBtn_H;
	Sprite* main_LGBtn;
	Sprite* main_OpBtn;
	Sprite* main_ExtBtn;
	Sprite* tileset;
	Sprite* hero;

	SDL_Rect passed_SrcR;
	SDL_Rect passed_DestR;
	
	SDL_Point m_mouseCoords;

};