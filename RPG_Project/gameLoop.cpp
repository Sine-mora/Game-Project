#include "Header.h"
#include "gameLoop.h"
#include "Game_Sprites.h"

Loop::Loop(int passed_ScreenWidth, int passed_ScreenHeight)
{
	ScreenWidth = passed_ScreenWidth;
	ScreenHeight = passed_ScreenHeight;

	quit = false;

	setup = new Setup(&quit, ScreenWidth, ScreenHeight);

	main_Menu_Background = new Sprite(setup->GetRenderer(), "res/Menu_BG.png", 0, 0, ScreenWidth, ScreenHeight);

	main_MBtn = new Sprite(setup->GetRenderer(), "res/Menu_buttons.png", 0, 0, ScreenWidth, ScreenHeight);

	passed_SrcR.x = 121;   passed_DestR.x = 154;
	passed_SrcR.y = 0;     passed_DestR.y = 60;
	passed_SrcR.w = 121;   passed_DestR.w = 300;
	passed_SrcR.h = 31;    passed_DestR.h = 63;

	main_MBtn_H = new Sprite(setup->GetRenderer(), "res/New_game_strip2.png",  passed_SrcR, passed_DestR);

	MouseX = 0;
	MouseY = 0;


	tileset = new Sprite(setup->GetRenderer(), "res/example_v1.1.png", 0, 0, ScreenWidth, ScreenHeight);

	hero = new Sprite(setup->GetRenderer(), "res/hero.gif", 300, 250, 150, 150);

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
	//delete tileset;
	//delete hero;
}

void Loop::GameLoop()
{
	const Uint8* state = SDL_GetKeyboardState(NULL);
	
	while (!quit && setup->GetMainEvent()->type != SDL_QUIT)
	{
		setup->Begin();

		SDL_GetMouseState(&MouseX, &MouseY);

		main_Menu_Background->Draw();

		if ((MouseX > 154 && MouseY > 61) && (MouseX < 454 && MouseY < 124))
		{
			main_MBtn_H->DrawR();
			std::cout << MouseX << " " << MouseY << std::endl;

			if (setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN)
			{
				std::cout << "Button pressed" << std::endl;
				tileset->Draw();
		        hero->Draw();

			}
		}
		else
		{
		main_MBtn->Draw();
		}






		

	
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
	
		/*if (setup->GetMainEvent()->button.button == SDL_MOUSEBUTTONDOWN)
		{
			std::cout << MouseX << " " << MouseY << std::endl;
		}*/


/*
		//TODO move to separate function
		switch (setup->GetMainEvent()->type)
		{
		case SDL_KEYDOWN:
			switch (setup->GetMainEvent()->key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			case SDLK_w:
				printf("W Keys Pressed.\n");
				//hero->SetY(-3);
				break;
			case SDLK_s:
				//hero->SetY(+3);
				break;
			case SDLK_a:
				printf("A Keys Pressed.\n");
				//hero->SetX(-3);
				break;
			case SDLK_d:
				//hero->SetX(+3);
				break;
			default:
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if ((MouseX > 154 && MouseY > 61) && (MouseX < 454 && MouseY < 124))
			{
				std::cout << MouseX << " " << MouseY << std::endl;
			}
				break;
		default:
			break;
		}
*/
		setup->End();
	}
}