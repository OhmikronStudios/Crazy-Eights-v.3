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
	
	Card(int v, int s, const SpriteLoader & spriteLoader);
	string getValue() const;
	string getSuit() const;
	string toString() const;


protected:

private:
	int m_value;
	int m_suit;
	const SpriteLoader &m_spriteLoader;

};

