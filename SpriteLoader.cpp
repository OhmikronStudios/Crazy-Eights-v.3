#include "SpriteLoader.h"
#include "Sprite.h"
#include "Card.h"

SpriteLoader::SpriteLoader(SDL_Renderer *renderer) : m_renderer(renderer)
{
	//We need to load the PNG and store the SDL_Texture
}

Sprite SpriteLoader::getSprite(const Card &card)
{
	return Sprite();
}

