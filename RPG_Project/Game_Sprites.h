#pragma once

//split separate images from the image array for the hero

class Sprite 
{
public:
	Sprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h);
	~Sprite();
	Sprite(SDL_Renderer* passed_renderer, std::string FilePath, SDL_Rect passed_SrcR, SDL_Rect passed_DestR);

	void Draw();
	void DrawR();

	void SetX(float x);
	void SetY(float y);
	void SetPosition(float x, float y);
	int GetX();
	int GetY();

private:
	SDL_Texture* image;
	SDL_Rect rect;
	SDL_Rect SrcR;
	SDL_Rect DestR;
	SDL_Renderer* renderer;

};