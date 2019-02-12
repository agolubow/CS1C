#ifndef HW02_H_
#define HW02_H_

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int DECK_SIZE = 52;
const int HALF_SIZE = 26;

struct cardType {
	string rank;
	string suit;
};

class cardDeckClass{

public:
	cardDeckClass();
	void print() const;
	void shuffle();
	bool compare(cardDeckClass&) const;
	string getSuit(int);
	string getRank(int);
private:
	string Suit[4] = {"Hearts","Clubs","Diamonds","Spades"};
	string Rank[13] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
	cardType cardDeck[DECK_SIZE]; //can split into two half decks for shuffle
};

#endif
