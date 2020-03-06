#pragma once


#include "Deck.h"


class Player
{
private:
	string m_name;
	Deck m_hand;

public:
	Player(string name);
	const string GetName() const;
	Card peekAtCard(int i);
	Deck getHand();


	string toString() const;

	void drawCard(Deck& fromDeck, int index);
	void playCard(Deck& toDeck, int index);

	int getHandSize();
	
	
	

	
	
};