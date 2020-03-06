#include "Deck.h"

#include <sstream>
#include <algorithm>
#include <random> 
#include <chrono>

Deck::Deck() 
{
  
}

void Deck::Shuffle()
{
    /*unsigned seed = chrono::system_clock::now()
        .time_since_epoch()
        .count();

    shuffle(m_deck.begin(), m_deck.end(), default_random_engine(seed));
    return;*/
    random_shuffle(m_deck.begin(), m_deck.end());
}

Card Deck::peekCard(int i)
{
    return m_deck[i];
}

Card Deck::peekTopCard()
{
    return m_deck[m_deck.size() -1];
}

string Deck::toString() const
{
    stringstream ss;
    for (int i = 0; i < m_deck.size(); ++i)
    {
        ss << " | Card"<< i << ":"  << m_deck[i].toString();
    }
    return ss.str();
}

void Deck::setupDeck()
{
    for (int suit = 0; suit < 4; suit++)
    {
        for (int value = 0; value < 13; value++)
        {
            Card card(value, suit);
            m_deck.push_back(card);
        }
    }
}

void Deck::moveCard(Deck& fromDeck, Deck& toDeck, int index)
{
    Card activeCard = fromDeck.m_deck[index];
    vector<Card>::iterator it = fromDeck.m_deck.begin();
    for (int i = 0; i < index; ++i)
    {
        ++it;
    }
    fromDeck.m_deck.erase(it);
    toDeck.m_deck.push_back(activeCard);
}

int Deck::getSize() const
{
    return m_deck.size();
}

