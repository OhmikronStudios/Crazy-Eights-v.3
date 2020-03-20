#include "Sprite.h"

Sprite::Sprite()
{

}

//Sprite::Sprite(const char* filename, int xpos, int ypos, int width, int height, SDL_Renderer* renderer)
//{
//	/** Set SDL_Renderer variable in Sprite class */
//	this->renderer = renderer;
//
//	/** Set SDL_Rect variable in Sprite class */
//	rect.x = 0;
//	rect.y = 0;
//	rect.h = height;
//	rect.w = width;
//
//	/** Set position variable of Sprite class */
//	this->xpos = xpos;
//	this->ypos = ypos;
//
//	/** Set visibility of Sprite class */
//	visible = true;
//
//	/** Load image to use for Sprite */
//	//load(filename);
//}

Sprite::~Sprite()
{
	/** Delete any resources created */
	//SDL_DestroyTexture(image);
}

//void Sprite::load(const char* filename)
//{
//	/** Load picture for Sprite */
//	image = IMG_LoadTexture(renderer, filename);
//
//	/** Check if the Sprite was loaded */
//	if (!image)
//	{
//		/** Bad stuff happened */
//		//cout << "IMG_LoadTexture Error: " << IMG_GetError() << endl;
//		exit(1);
//	}
//}

//void Sprite::draw()
//{
//	/** Check if sprite should be drawn to the screen */
//	if (this->visible)
//	{
//		/** Position sprite on Screen */
//		SDL_Rect dest = { xpos, ypos, rect.w, rect.h };
//
//		/** Draw Sprite to Screen */
//		SDL_RenderCopy(renderer, image, &rect, &dest);
//	}
//}
//
//SDL_Texture* Sprite::getImage()
//{
//	return this->image;
//}