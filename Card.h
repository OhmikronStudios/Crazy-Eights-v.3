#pragma once
#include <iostream>
#include <string>
using namespace std;

class Card
{
public:
	Card();
	Card(int v, int s);
	string getValue() const;
	string getSuit() const;
	string toString() const;

protected:

private:
	int m_value;
	int m_suit;
};

