#include "hw05.h"

int main(){
	srand(time(NULL));
	vector<int> winners;
	int numberOfSpots;
	int numberSelected;
	cout <<endl<<"Please enter the number of spots on the Lotto Card: ";
	while(!(cin >> numberOfSpots)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout <<endl<<"Please enter the number of spots on the Lotto Card: ";
	}
	cout <<endl<<"Please enter the number of spots to be selected at random: ";
	while(!(cin >> numberSelected)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout <<endl<< "Please enter the number of spots to be selected at random: ";
	}
	winners = Lotto(numberOfSpots,numberSelected);
	cout <<endl<<"The winning numbers are: ";
	for (auto i = winners.begin();i != winners.end();i++) {
    	cout << *i <<" ";
	}
	return 0;
}

vector<int> Lotto(int numberOfSpots,int numberSelected){
	vector<int> toShuffle;
	for(int i=1;i<=numberOfSpots;i++){
		toShuffle.push_back(i);
	}
	random_shuffle(toShuffle.begin(),toShuffle.end());
	vector<int> winners;
	for(int index = 0; index < numberSelected; ++index){
		winners.push_back(toShuffle[index]);
	}
	return winners;
}