#include "Header.h"
#include "gameLoop.h"
#include "Game_Sprites.h"

Loop::Loop(int passed_ScreenWidth, int passed_ScreenHeight)
	: m_eGameState(eMainMenu),
	  m_btnNewGame(),
	  m_mouseCoords{ 0, 0 }
{
	ScreenWidth = passed_ScreenWidth;
	ScreenHeight = passed_ScreenHeight;

	quit = false;

	setup = new Setup(&quit, ScreenWidth, ScreenHeight);

	main_Menu_Background = new Sprite(setup->GetRenderer(), "res/Menu_BG.png", 0, 0, ScreenWidth, ScreenHeight);

	main_MBtn = new Sprite(setup->GetRenderer(), "res/Menu_buttons.png", 0, 0, ScreenWidth, ScreenHeight);

	passed_SrcR.x = 121;   passed_DestR.x = 203;
	passed_SrcR.y = 0;     passed_DestR.y = 73;
	passed_SrcR.w = 121;   passed_DestR.w = 403;
	passed_SrcR.h = 31;    passed_DestR.h = 76;
//	main_MBtn_H = new Sprite(setup->GetRenderer(), "res/New_game_strip2.png",  passed_SrcR, passed_DestR);

	auto callback = [this]()
	{
		m_eGameState = ePlayGame;
		std::cout << "Button pressed" << std::endl;
	};
	bool isSuccess = m_btnNewGame.Init(setup->GetRenderer(), "res/New_game_strip2.png", passed_DestR, callback);
	if (!isSuccess)
	{
		exit(1);
	}
	passed_SrcR.x = 121;   passed_DestR.x = 181;
	passed_SrcR.y = 0;     passed_DestR.y = 169;
	passed_SrcR.w = 121;   passed_DestR.w = 448;
	passed_SrcR.h = 31;    passed_DestR.h = 75;
	main_LGBtn = new Sprite(setup->GetRenderer(), "res/Load_game_strip2.png", passed_SrcR, passed_DestR);

	passed_SrcR.x = 121;   passed_DestR.x = 220;
	passed_SrcR.y = 0;     passed_DestR.y = 260;
	passed_SrcR.w = 121;   passed_DestR.w = 356;
	passed_SrcR.h = 31;    passed_DestR.h = 82;
	main_OpBtn = new Sprite(setup->GetRenderer(), "res/Options_strip2.png", passed_SrcR, passed_DestR);

	passed_SrcR.x = 121;   passed_DestR.x = 290;
	passed_SrcR.y = 0;     passed_DestR.y = 370;
	passed_SrcR.w = 121;   passed_DestR.w = 270;
	passed_SrcR.h = 31;    passed_DestR.h = 67;
	main_ExtBtn = new Sprite(setup->GetRenderer(), "res/Exit_strip2.png", passed_SrcR, passed_DestR);


	tileset = new Sprite(setup->GetRenderer(), "res/prologue map.png", 0, 0, ScreenWidth, ScreenHeight);

	hero = new Sprite(setup->GetRenderer(), "res/hero.gif", -10, 100, 120, 120);

	//hero = IMG_LoadTexture(setup->GetRenderer(), "res/chara_hero.png");
}/*
	hero_rect.x = 124;
	hero_rect.y = 124;
	hero_rect.w = 64;
	hero_rect.h = 64;

	hero_source.x = 16;
	hero_source.y = 16;
	hero_source.w = 16;
	hero_source.h = 16;

	if (hero == nullptr) {
		std::cerr << "Couldn't load hero\n";
	}
}*/

Loop::~Loop() 
{
	//SDL_DestroyTexture(hero);

	delete main_Menu_Background;
	delete main_MBtn;
	delete main_MBtn_H;
	delete setup;
	delete tileset;
	delete hero;
}

void Loop::GameLoop()
{
	const Uint8* state = SDL_GetKeyboardState(NULL);
	bool flag_menu = true;

	
	while (!quit && setup->GetMainEvent()->type != SDL_QUIT)
	{
		setup->Begin();

		OnUpdate(setup->GetMainEvent());
		OnDraw();

		//Enable diagonal movement
		/*if (state[SDL_SCANCODE_1]) {
			printf("<1> is pressed.\n");
		}
		if (state[SDL_SCANCODE_3] && state[SDL_SCANCODE_2]) {
			printf("3 and 2 Keys Pressed.\n");
			//hero->SetY(-1);
			//hero->SetX(-2);
		}
		if (state[SDL_SCANCODE_2] && state[SDL_SCANCODE_3]) {
			printf("2 and 3 Keys Pressed.\n");
			//hero->SetY(-1);
			//hero->SetX(-2);
		}*/

		setup->End();
	}
}

void Loop::OnUpdate(SDL_Event* ptrEvent)
{
	SDL_GetMouseState(&m_mouseCoords.x, &m_mouseCoords.y);

	//if (setup->GetMainEvent()->button.button == SDL_MOUSEBUTTONDOWN)
	//{
	//	std::cout << m_mouseCoords.x << " " << m_mouseCoords.y << std::endl;
	//}

	switch (m_eGameState)
	{
	case eMainMenu:
		m_btnNewGame.OnTouch(ptrEvent, m_mouseCoords);
		break;
	case ePlayGame:
		//TODO move to separate function
		switch (setup->GetMainEvent()->type)
		{
		case SDL_KEYDOWN:
			switch (setup->GetMainEvent()->key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_eGameState = eMainMenu;
				break;
			case SDLK_q: quit = true; break;
			case SDLK_w:
				printf("W Keys Pressed.\n");
				hero->SetY(-3);
				break;
			case SDLK_s:
				hero->SetY(+3);
				break;
			case SDLK_a:
				printf("A Keys Pressed.\n");
				hero->SetX(-3);
				break;
			case SDLK_d:
				hero->SetX(+3);
				break;
			default:
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if ((m_mouseCoords.x > 154 && m_mouseCoords.y > 61) && (m_mouseCoords.x < 454 && m_mouseCoords.y < 124))
			{
				std::cout << m_mouseCoords.x << " " << m_mouseCoords.y << std::endl;
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void Loop::OnDraw()
{
	std::cout << "state is " << m_eGameState << "\n";
	switch (m_eGameState)
	{
	case eMainMenu:
		main_Menu_Background->Draw();
		main_MBtn->Draw();
		m_btnNewGame.Draw();
		break;
	case ePlayGame:
		tileset->Draw();
		hero->Draw();
		break;
	default:
		break;
	}
}
