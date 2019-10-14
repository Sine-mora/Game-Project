#include "MainMenuButton.h"

MainMenuButton::MainMenuButton():
	m_ptrSprite(new Sprite()),
	m_isPressed(false),
	m_srcRectNotPressed{0, 0, 0, 0},
	m_srcRectPressed{0, 0, 0, 0}
{
}

bool MainMenuButton::Init(SDL_Renderer* renderer, const std::string& strPath,
	const SDL_Rect& destRect, const Callback& callback)
{
	if (!m_ptrSprite->Init(renderer, strPath))
	{
		return false;
	}

	m_ptrSprite->SetDestRect(destRect);

	const SDL_Rect& srcRect = m_ptrSprite->GetSrcRect();
	m_srcRectNotPressed = {0, 0, srcRect.w / 2, srcRect.h};
	m_srcRectPressed = { srcRect.w / 2, 0, srcRect.w / 2, srcRect.h };

	m_callback = callback;
	return true;
}

void MainMenuButton::Draw()
{
	m_ptrSprite->DrawR();
}

void MainMenuButton::OnTouch(SDL_Event* event, const SDL_Point& touchCoords)
{
	bool isCoordInBtn = SDL_PointInRect(&touchCoords, &m_ptrSprite->GetDestRect());
	const SDL_Rect& rect = isCoordInBtn ? m_srcRectPressed : m_srcRectNotPressed;
	m_ptrSprite->SetSrcRect(rect);	
	m_isPressed = (event->type == SDL_MOUSEBUTTONDOWN) && isCoordInBtn;
	if (m_isPressed && m_callback)
	{
		m_callback();
	}
}
