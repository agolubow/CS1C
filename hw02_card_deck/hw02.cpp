#include "cardDeckClass.h"

int main(){
	cardDeckClass deckOne;
	cardDeckClass deckTwo;
	cout << "-----INITIAL DECK-----"<<endl<<endl;
	deckOne.print();
	deckOne.shuffle();
	cout <<endl<<"--AFTER FIRST SHUFFLE--"<<endl<<endl;
	deckOne.print();
	int i=1;
	while(!deckOne.compare(deckTwo)){
		deckOne.shuffle();
		i++;
	}
	cout <<endl<<"------FINAL DECK------"<<endl<<endl;
	deckOne.print();
	cout <<endl<<"The original deck was shuffled "<<i<<" times before returning to its original configuration"<<endl;

	return 0;
}