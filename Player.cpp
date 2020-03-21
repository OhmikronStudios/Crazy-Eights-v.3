#include "Player.h"
#include <sstream>



Player::Player(string name) : m_name(name){}

const string Player::GetName() const
{
	return m_name;
}

string Player::toString() const
{
	stringstream ss;
	ss << "It is " << m_name << "'s turn." << endl << "Your hand is: " << m_hand.toString() << endl;
	return ss.str();
}

void Player::drawCard(Deck& fromDeck, int index)
{
	Deck::moveCard(fromDeck, m_hand, index);
}

void Player::playCard(Deck& toDeck, int index)
{
	Deck::moveCard(m_hand, toDeck, index);
}

int Player::getHandSize()
{
	return m_hand.getSize();
}

Deck Player::getHand()
{
	return m_hand;
}

Card Player::peekAtCard(int i)
{
	return m_hand.peekCard(i);
}

int Player::paint(SDL_Renderer* renderer, int posX, int posY)
{
	return m_hand.paint(renderer, posX, posY);
	
}







