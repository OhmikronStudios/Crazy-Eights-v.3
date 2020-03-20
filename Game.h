#pragma once

#include "Deck.h"
#include "Card.h"   
#include "Player.h"
#include "SpriteLoader.h"




class Game
{
	vector<Player> m_players;
	Deck m_drawPile;
	Deck m_discardPile;
	int m_currentPlayer;
	//bool isValidCard(Card);
	const SpriteLoader &m_spriteLoader;

public:

	Game(const SpriteLoader &spriteLoader);

	Player playGame();

	void addPlayer(string name);
	
	// int getPlayerCount(); //made redundant with m_players.size()
	

};

