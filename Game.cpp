#include "Game.h"
#include <iostream>
#include <algorithm>
#include <random> 
#include <chrono>

Game::Game() {}



void Game::addPlayer(string name)
{
	Player player(name);
	m_players.push_back(player);
}

Player Game::playGame()
{
	m_drawPile.setupDeck();
	m_drawPile.Shuffle();

	for (int i = 0; i < m_players.size(); i++)
	{
		for (int j = 0; j < 8; j++)
		{
			m_players[i].drawCard(m_drawPile, 0);
			cout << m_players[i].toString() << endl;
		}
	}

	Deck::moveCard(m_drawPile, m_discardPile, 0);
	

	unsigned seed = chrono::system_clock::now()
		.time_since_epoch()
		.count();
	currentPlayer = seed % m_players.size();

	bool gameOver = false;
	while (gameOver == false)
	{
		cout << "The current card to play on is: " << m_discardPile.peekTopCard().toString() << endl;
		cout << m_players[currentPlayer].toString() << endl;
		cout << "Please select a card to play from your hand" << endl;

		int chosenCard;
		cin >> chosenCard;
		if (chosenCard > m_players[currentPlayer].getHandSize() || chosenCard < -1)
		{
			continue;
		}
		
		else if (chosenCard == -1)
		{
			if (currentPlayer == m_players.size() - 1)
			{currentPlayer = 0;}
			
			else
			{currentPlayer += 1;}
		}

		else
		{
			Card selectedCard = m_players[currentPlayer].peekAtCard(chosenCard);
			Card targetCard = m_discardPile.peekTopCard();
			
			if (selectedCard.getValue() == "7" || 
				selectedCard.getValue() == targetCard.getValue() || 
				selectedCard.getSuit() == targetCard.getSuit())
			{
				//Deck::moveCard(m_players[currentPlayer].getHand(), m_discardPile, chosenCard);
				m_players[currentPlayer].playCard(m_discardPile, chosenCard);
			}
			
			else
			{
				continue;
			}
		}




	}
	return m_players[currentPlayer];
}