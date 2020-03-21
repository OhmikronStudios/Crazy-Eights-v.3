#include "Game.h"

#include <iostream>
#include <algorithm>
#include <random> 
#include <chrono>


Game::Game() : m_currentPlayer (0)
{

}

void Game::addPlayer(string name)
{
	Player player(name);
	m_players.push_back(player);
}

Player Game::playGame(SDL_Renderer* renderer) 
{
	//Create and shuffle the draw deck
	m_drawPile.setupDeck();
	
	m_drawPile.Shuffle();


	
	

	//Deal cards to each player
	for (int i = 0; i < m_players.size(); i++)
	{
		for (int j = 0; j < 8; j++)
		{
			m_players[i].drawCard(m_drawPile, 0);
			//cout << m_players[i].toString() << endl;
		}
	}

	//Deal one more card to the discard pile as the starting card
	Deck::moveCard(m_drawPile, m_discardPile, 0);
	
	//Randomize first player
	unsigned seed = chrono::system_clock::now()
		.time_since_epoch()
		.count();
	m_currentPlayer = seed % m_players.size();
	
	int jacksPlayed = 0;
	int cardsPlayed = 0;
	bool gameOver = false;
	string tempSuit;

	while (gameOver == false)
	{
		
		SDL_RenderClear(renderer);
		//Start of turn instructions
		m_discardPile.peekTopCard().paint(renderer, 100, 50);
		
		cout << m_players[m_currentPlayer].toString() << endl;
		m_players[m_currentPlayer].paint(renderer, 100, 300);
		
		
		cout << m_players[m_currentPlayer].GetName() << ", please select a card to play from your hand" << endl << "If you are finished with your turn, enter -1 to pass." << endl << endl;
		if (m_discardPile.peekTopCard().getValue() != "8")
		{
			cout << "The current card on top of the discard pile is: " << m_discardPile.peekTopCard().toString() << endl;
		}
		else if (m_discardPile.peekTopCard().getValue() == "8")
		{
			cout << "Due to a magic 8, the suit to play is: " << tempSuit << endl;
		}
		SDL_RenderPresent(renderer);

		int chosenCard;
		//cin >> chosenCard;

		SDL_Event event;

		while (true)
		{
			int errorCode = SDL_WaitEvent(&event);
			if (errorCode == 1)
			{
				if (event.type ==  SDL_MOUSEBUTTONUP)
				{
					cout << event.button.x << endl;
					cout << event.button.y << endl;

					if (event.button.y >= 300 && event.button.y < 363)
					{
						int Xindex = (event.button.x - 100) / 45.0;
						cout << Xindex << endl;
						if (Xindex >= 0 && Xindex <= m_players[m_currentPlayer].getHandSize())
						{
							if (Xindex == m_players[m_currentPlayer].getHandSize())
							{
								chosenCard = -1;
							}
							else
							{
								chosenCard = Xindex;
							}
							break;
						}

					}

				}
			}
		}


		//Invalid entry returns to start of turn
		if (chosenCard > m_players[m_currentPlayer].getHandSize() || chosenCard < -1)
		{
			continue;
		}
		
		// -1 entry ends the turn
		else if (chosenCard == -1)
		{
			if (cardsPlayed == 0)
			{
				m_players[m_currentPlayer].drawCard(m_drawPile, 0);
			}			
				
			for (int i = 0; i < 1 + jacksPlayed; i++)
			{
				if (m_currentPlayer == m_players.size() - 1)
				{
					m_currentPlayer = 0;
				}

				else
				{
					m_currentPlayer += 1;
				}
			}
			//new players turn - resetting the two turn dependant variables
			cardsPlayed = 0;
			jacksPlayed = 0;
		}

		//Any other entry is a card play attempt
		else
		{
			Card selectedCard = m_players[m_currentPlayer].peekAtCard(chosenCard);
			Card targetCard = m_discardPile.peekTopCard();
			
			//As long as the last card wasn't an 8, play main loop
			if (targetCard.getValue() != "8")
			{
				if (cardsPlayed == 0)
				{
					if (selectedCard.getValue() == "8" ||
						selectedCard.getValue() == targetCard.getValue() ||
						selectedCard.getSuit() == targetCard.getSuit())
					{
						m_players[m_currentPlayer].playCard(m_discardPile, chosenCard);
						cardsPlayed += 1;
						if (m_players[m_currentPlayer].getHandSize() == 0)
						{
							gameOver = true;
							continue;
						}
					}
					else
					{
						continue;
					}
				}
				//playing a 2nd (or more) cards means only the value matters
				else if (cardsPlayed > 0)
				{
					if (selectedCard.getValue() == targetCard.getValue())
					{
						m_players[m_currentPlayer].playCard(m_discardPile, chosenCard);
						cardsPlayed += 1;
						if (m_players[m_currentPlayer].getHandSize() == 0)
						{
							gameOver = true;
							continue;
						}
					}
					else
					{
						continue;
					}
				}
			}

			//If the last card was an 8, play this instead
			else
			{
				
				if (selectedCard.getValue() == "8" ||
					selectedCard.getSuit() == tempSuit)
				{
					m_players[m_currentPlayer].playCard(m_discardPile, chosenCard);
					cardsPlayed += 1;
					if (m_players[m_currentPlayer].getHandSize() == 0)
					{
						gameOver = true;
						continue;
					}
				}

				else
				{
					continue;
				}
				
				
			}

			//Special Card scenarios
			if (selectedCard.getValue() == "2")
			{
				int targetPlayer;
				if (m_currentPlayer == m_players.size() - 1)
				{
					targetPlayer = 0;
				}

				else
				{
					targetPlayer = m_currentPlayer+1;
				}
				m_players[targetPlayer].drawCard(m_drawPile, 0);
				m_players[targetPlayer].drawCard(m_drawPile, 0);
			}

			else if (selectedCard.getValue() == "J")
			{
				jacksPlayed += 1;
			}

			else if (selectedCard.getValue() == "8")
			{
				int suitEntered;
				cout << "You played a magic 8! What suit would you like to make it?" << endl;
				cout << "0: Clubs, 1: Diamonds, 2: Hearts, 3: Spades" << endl;
				cin >> suitEntered;
				
				switch (suitEntered)
				{
					case 0: tempSuit = "C"; break;
					case 1: tempSuit = "D"; break;
					case 2: tempSuit = "H"; break;
					case 3: tempSuit = "S"; break;
				}
				m_currentPlayer += 1;
			}
		}

		system("CLS"); //only happening if the player plays a valid card, otherwise this gets skipped.

	}
	cout << "Congratulations " << m_players[m_currentPlayer].GetName() << ". You win!" << endl;
	return m_players[m_currentPlayer];
}