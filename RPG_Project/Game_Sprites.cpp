#include "Header.h"
#include "Game_sprites.h"

Sprite::Sprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h)
{
	renderer = passed_renderer;
	image = nullptr;
	image = IMG_LoadTexture(renderer, FilePath.c_str());

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	if (image == nullptr)
	{
		std::cout << "Couldn't Load " << FilePath.c_str() << std::endl;
	}
}

Sprite::Sprite(SDL_Renderer* passed_renderer, std::string FilePath,SDL_Rect passed_SrcR, SDL_Rect passed_DestR)
{
	renderer = passed_renderer;
	SrcR = passed_SrcR;
	DestR = passed_DestR;

	image = nullptr;
	image = IMG_LoadTexture(renderer, FilePath.c_str());

	SrcR.x = passed_SrcR.x; DestR.x = passed_DestR.x;
	SrcR.y = passed_SrcR.y; DestR.y = passed_DestR.y;
	SrcR.w = passed_SrcR.w; DestR.w = passed_DestR.w;
	SrcR.h = passed_SrcR.h; DestR.h = passed_DestR.h;

	if (image == nullptr)
	{
		std::cout << "Couldn't Load " << FilePath.c_str() << std::endl;
	}
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(image);

}

void Sprite::Draw() 
{
	SDL_RenderCopy(renderer, image, NULL, &rect);
}

void Sprite::DrawR()
{
	SDL_RenderCopy(renderer, image, &SrcR, &DestR);
}

void Sprite::SetX(float x)
{
	rect.x = rect.x + x;
}
void Sprite::SetY(float y)
{
	rect.y += y;
}
void Sprite::SetPosition(float x, float y)
{
	rect.x = rect.x + x;
	rect.y += y;
}
int Sprite::GetX()
{
	return rect.x;
}
int Sprite::GetY()
{
	return rect.y;
}