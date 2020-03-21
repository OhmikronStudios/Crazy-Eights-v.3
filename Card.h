#pragma once
#include "Definitions.h"
#include "Sprite.h"
#include "SpriteLoader.h"
#include <iostream>
#include <string>
using namespace std;

class Card
{
public:
	
	Card(int v, int s);
	string getValue() const;
	string getSuit() const;
	string toString() const;
	int paint(SDL_Renderer*, int posX, int posY);
	int getWidth() const;
	int getHeight() const;

protected:

private:
	int m_value;
	int m_suit;
	int m_spriteWidth;
	int m_spriteHeight;

	//const SpriteLoader *m_spriteLoader;

};

