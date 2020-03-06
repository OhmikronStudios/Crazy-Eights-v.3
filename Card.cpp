#include "Card.h"
#include <sstream>
#include <iostream>

Card::Card()
{

}

Card::Card(int v, int s)
{
	m_value = v;
	m_suit = s;
}


string Card::getValue() const
{
	switch (m_value)
	{
	case 0: return "A";
	case 1: return "2";
	case 2: return "3";
	case 3: return "4";
	case 4: return "5";
	case 5: return "6";
	case 6: return "7";
	case 7: return "8";
	case 8: return "9";
	case 9: return "10";
	case 10: return "J";
	case 11: return "Q";
	case 12: return "K";
	}
	return "Invalid";
}
string Card::getSuit() const
{
	switch (m_suit)
	{
	case 0: return "S";
	case 1: return "C";
	case 2: return "H";
	case 3: return "D";
	}
	return "Invalid";
}

string Card::toString() const
{
	





	stringstream ss;

	ss << getValue() << getSuit();
	return ss.str();
}
