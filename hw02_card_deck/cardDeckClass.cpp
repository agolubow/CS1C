#include "cardDeckClass.h"

cardDeckClass::cardDeckClass(){
	int j=0;
	for(int i=0;i<52;i++){
		if(i<13){
			cardDeck[i].suit = Suit[0];
		}else if(i<26){
			cardDeck[i].suit = Suit[1];
		}else if(i<39){
			cardDeck[i].suit = Suit[2];
		}else{
			cardDeck[i].suit = Suit[3];
		}
		if(i%13 == 0){
			j=0;
		}else{
			j++;
		}
		cardDeck[i].rank = Rank[j];
	}
}

void cardDeckClass::print() const{
	for(int i=0;i<52;i++){
		cout <<setw(4)<<right<<(i+1)<<". "<<setw(6)<<left<<cardDeck[i].rank<<" of "<<cardDeck[i].suit<<endl;
	}
	return;
}

void cardDeckClass::shuffle(){
	cardType halfDeckOne[HALF_SIZE];
	cardType halfDeckTwo[HALF_SIZE];
	int i;
	int j=0;
	for(i=0;i<26;i++){
		halfDeckOne[i].rank = cardDeck[i].rank;
		halfDeckOne[i].suit = cardDeck[i].suit;
		halfDeckTwo[i].rank = cardDeck[i+26].rank;
		halfDeckTwo[i].suit = cardDeck[i+26].suit;
	}

	for(i=0;i<52;i++){
		cardDeck[i].suit = halfDeckOne[j].suit;
		cardDeck[i].rank = halfDeckOne[j].rank;
		i++;
		cardDeck[i].suit = halfDeckTwo[j].suit;
		cardDeck[i].rank = halfDeckTwo[j].rank;
		j++;
	}
	return;
}

string cardDeckClass::getSuit(int index){
	return cardDeck[index].suit;
}
string cardDeckClass::getRank(int index){
	return cardDeck[index].rank;
}

bool cardDeckClass::compare(cardDeckClass& other) const{
	for(int i=0;i<52;i++){
		if(cardDeck[i].suit != other.getSuit(i) || cardDeck[i].rank != other.getRank(i)){
			return false;
		}
	}
	return true;
}