#pragma once

#include "Deck.h"
#include "Card.h"   
#include "Player.h"





class Game
{
	vector<Player> m_players;
	Deck m_drawPile;
	Deck m_discardPile;
	int m_currentPlayer;
	//bool isValidCard(Card);


public:

	Game();

	Player playGame(SDL_Renderer* renderer);

	void addPlayer(string name);
	
	// int getPlayerCount(); //made redundant with m_players.size()
	

};

