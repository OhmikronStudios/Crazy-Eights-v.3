#pragma once

#include "Definitions.h"

class Sprite
{
public:
	Sprite();
	//Sprite(const char* filename, int xpos, int ypos, int width, int height, SDL_Renderer* renderer);
	~Sprite();
	void draw(SDL_Renderer *renderer, SDL_Rect dest);
	//SDL_Texture* getImage();

private:
	//void load(const char* filename);

	SDL_Texture* sourceImage;
	SDL_Rect source;
	SDL_Rect dim;

	

};

