#pragma once

#include "Deck.h"
#include "Card.h"   
#include "Player.h"


class Game
{
	vector<Player> m_players;
	Deck m_drawPile;
	Deck m_discardPile;
	int currentPlayer;
	bool isValidCard(Card);


public:
	Game();

	Player playGame();

	void addPlayer(string name);
	
	int getPlayerCount();
	

};

