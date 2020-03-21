#pragma once
#include "Definitions.h"

class Card;
class Sprite;


class SpriteLoader
{
public:
	SpriteLoader(SDL_Renderer *renderer);
	Sprite getSprite(const Card& card);




private:
	SDL_Renderer* m_renderer;


};

