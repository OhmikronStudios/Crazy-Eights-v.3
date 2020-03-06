#include "Player.h"
#include <sstream>



Player::Player(string name)
{
	m_name = name;
	return;
}

const string Player::GetName() const
{
	return m_name;
}

string Player::toString() const
{
	stringstream ss;
	
	ss << m_name << "'s Hand is: " << m_hand.toString();

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










