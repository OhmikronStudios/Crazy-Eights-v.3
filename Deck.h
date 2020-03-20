#pragma once

#include <vector>
#include "Card.h"
#include "SpriteLoader.h"

class Deck
{
	vector<Card> m_deck;
	const SpriteLoader &m_spriteLoader;

	

public:

	Deck(const SpriteLoader &spriteLoader);
	void setupDeck();
	string toString() const;
	

	void Shuffle();
	Card peekCard(int i);
	Card peekTopCard();
	static void moveCard(Deck& fromDeck, Deck& toDeck, int index);
	//void removeCard(Deck toDeck, int index); //not using this anymore
	int getSize() const;


};

