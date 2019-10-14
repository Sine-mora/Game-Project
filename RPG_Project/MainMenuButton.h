#pragma once
#include "Header.h"
#include "Game_Sprites.h"
#include <functional>

class MainMenuButton
{
public:
	using Callback = std::function<void()>;
	MainMenuButton();
	bool Init(SDL_Renderer* renderer, const std::string& strPath, const SDL_Rect& destRect, const Callback& callback);
	void Draw();
	void OnTouch(SDL_Event* event, const SDL_Point& touchCoords);


private:

	Sprite* m_ptrSprite;
	bool m_isPressed;
	SDL_Rect m_srcRectNotPressed;
	SDL_Rect m_srcRectPressed;
	Callback m_callback;
};

