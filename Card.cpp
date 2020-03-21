#include "Card.h"
#include <sstream>
#include <iostream>


Card::Card(int v, int s) : m_value(v), m_suit(s), m_spriteWidth(45), m_spriteHeight(63)
{

}

string Card::getValue() const
{
	switch (m_value)
	{
	case 0: return "A";
	case 1: return "2";
	case 2: return "3";
	case 3: return "4";
	case 4: return "5";
	case 5: return "6";
	case 6: return "7";
	case 7: return "8";
	case 8: return "9";
	case 9: return "10";
	case 10: return "J";
	case 11: return "Q";
	case 12: return "K";
	}
	return "Invalid";
}

string Card::getSuit() const
{
	switch (m_suit)
	{
	case 0: return "C";
	case 1: return "D";
	case 2: return "H";
	case 3: return "S";
	}
	return "Invalid";
}

string Card::toString() const
{
	stringstream ss;
	ss << getValue() << getSuit();
	return ss.str();
}

int Card::getWidth() const
{
	return m_spriteWidth;
}

int Card::getHeight() const
{
	return m_spriteHeight;
}

int Card::paint(SDL_Renderer* renderer, int xPos, int yPos)
{
	
	/** Load picture for Sprite */
	SDL_Texture *image = IMG_LoadTexture(renderer, "CardsSmall.jpg");

	/** Check if the Sprite was loaded */
	if (!image)
	{
		/** Bad stuff happened */
		cerr << "IMG_LoadTexture Error: " << IMG_GetError() << endl;
		return (1);
	}

	//draw
	/** Position sprite on Screen */
	SDL_Rect source = { m_value*m_spriteWidth, m_suit*m_spriteHeight, m_spriteWidth, m_spriteHeight };
	SDL_Rect dest = {xPos, yPos, m_spriteWidth, m_spriteHeight};

	/** Draw Sprite to Screen */
	int errorCode = SDL_RenderCopy(renderer, image, &source, &dest);
	
	if (errorCode != 0)
	{
		/** Bad stuff happened */
		cerr << "SDL_RenderCopy Error: " << IMG_GetError() << endl;
		return (1);
	}
	SDL_DestroyTexture(image);
	return(0);
	
}