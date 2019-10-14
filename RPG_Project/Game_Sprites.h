#pragma once

//split separate images from the image array for the hero

class Sprite 
{
public:
	Sprite();
	Sprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h);
	~Sprite();
	Sprite(SDL_Renderer* passed_renderer, std::string FilePath, SDL_Rect passed_SrcR, SDL_Rect passed_DestR);

	bool Init(SDL_Renderer* passed_renderer, std::string FilePath);

	void Draw();
	void DrawR();

	void SetSrcRect(const SDL_Rect& srcRect);
	const SDL_Rect& GetSrcRect() const;

	void SetDestRect(const SDL_Rect& destRect);
	const SDL_Rect& GetDestRect() const;

	void SetX(float x);
	void SetY(float y);
	void SetPosition(float x, float y);
	int GetX();
	int GetY();

private:
	SDL_Texture* image;
	SDL_Rect SrcR;
	SDL_Rect DestR;
	SDL_Renderer* renderer;

};