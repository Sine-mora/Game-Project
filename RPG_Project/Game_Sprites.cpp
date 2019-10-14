#include "Header.h"
#include "Game_sprites.h"

Sprite::Sprite():
	image(nullptr),
	SrcR{ 0, 0, 0, 0 },
	DestR{0, 0, 0, 0},
	renderer(nullptr)
{
}

Sprite::Sprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h) :
	SrcR{ 0, 0, 0, 0}, DestR{x, y, w, h}
{
	renderer = passed_renderer;
	image = nullptr;
	image = IMG_LoadTexture(renderer, FilePath.c_str());

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

	SrcR.x = passed_SrcR.x; DestR.x = passed_DestR.x;
	SrcR.y = passed_SrcR.y; DestR.y = passed_DestR.y;
	SrcR.w = passed_SrcR.w; DestR.w = passed_DestR.w;
	SrcR.h = passed_SrcR.h; DestR.h = passed_DestR.h;

	image = IMG_LoadTexture(renderer, FilePath.c_str());
	if (image == nullptr)
	{
		std::cout << "Couldn't Load " << FilePath.c_str() << std::endl;
	}
}

bool Sprite::Init(SDL_Renderer* passed_renderer, std::string FilePath)
{
	renderer = passed_renderer;
	if (!renderer)
	{
		std::cout << "Sprite::Init() ERROR! file " << FilePath.c_str() << "\tEmpty Renderer!\n";
		return false;
	}
	image = IMG_LoadTexture(renderer, FilePath.c_str());
	if (image == nullptr)
	{
		std::cout << "Sprite::Init() ERROR! Couldn't Load " << FilePath.c_str() << std::endl;
		return false;
	}

	SrcR.x = 0;
	SrcR.y = 0;

	//Retrieve texture attributes
	if (SDL_QueryTexture(image, nullptr, nullptr,
		&SrcR.w, &SrcR.h) != 0)
	{
		std::cerr << "SpriteComponent::Error executing texture query!\n";
		return false;
	}
	return true;
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(image);

}

void Sprite::Draw() 
{
	SDL_RenderCopy(renderer, image, NULL, &DestR);
}

void Sprite::DrawR()
{
	SDL_RenderCopy(renderer, image, &SrcR, &DestR);
}

void Sprite::SetSrcRect(const SDL_Rect& srcRect)
{
	SrcR = srcRect;
}

const SDL_Rect& Sprite::GetSrcRect() const
{
	return SrcR;
}


void Sprite::SetDestRect(const SDL_Rect& destRect)
{
	DestR = destRect;
}

const SDL_Rect& Sprite::GetDestRect() const
{
	return DestR;
}

void Sprite::SetX(float x)
{
	DestR.x = DestR.x + x;
}
void Sprite::SetY(float y)
{
	DestR.y += y;
}
void Sprite::SetPosition(float x, float y)
{
	SetX(x);
	SetY(y);
}
int Sprite::GetX()
{
	return DestR.x;
}
int Sprite::GetY()
{
	return DestR.y;
}