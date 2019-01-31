#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

int generateRandom();
int triple(int);
int sum(int);
void bubbleSort(int numArray[10],int);
void readFile(string);
void print(int theArray[10]);

int main(){
	
	int choice = 4;
	srand(time(NULL));
	typedef int int_r;
	int_r random;
	while(choice != 0){
		random = generateRandom();
		cout << "Your random number is "<<random<<endl;
		cout << "Please select one."<<endl
			<<"1. Sum the digits"<<endl
			<<"2. Triple the number"<<endl
			<<"3. Reverse the digits"<<endl
			<<"0. Quit"<<endl<<endl;

		while(!(cin>>choice)){
			cin.clear();
			cin.ignore();
			cout << "Please select one."<<endl
			<<"1. Sum the digits"<<endl
			<<"2. Triple the number"<<endl
			<<"3. Reverse the digits"<<endl
			<<"0. Quit"<<endl<<endl;
		}

		switch(choice){
			case 1:
				cout<<"The digits summed is "<<sum(random)<<endl<<endl;
				cout<<"Press enter to continue..."<<endl;
				cin.get();
				cin.clear();
				cin.ignore(1000,'\n');
			break;
			case 2:
				cout<<"The number tripled is "<<triple(random)<<endl<<endl;
				cout<<"Press enter to continue..."<<endl;
				cin.get();
				cin.clear();
				cin.ignore(1000,'\n');
			break;
			case 3:
				int first;
				int second;
				int third;

				third = random % 10;
				second = random/10 % 10;
				first =random/100 % 10;

				cout<<"The number reversed is "<<third<<second<<first<<endl<<endl;
				cout<<"Press enter to continue..."<<endl;
				cin.get();
				cin.clear();
				cin.ignore(1000,'\n');

			break;
			case 0:
			break;

			default:
				cout<<"Please enter a number between 0 and 3"<<endl<<endl;
		}

	}

	int randarray[10];
	int i;

	for(i=0;i<10;i++){
		randarray[i] = rand();
	}

	bubbleSort(randarray,10);
	ofstream output;
	output.open("hw01.txt");

	for(i=0;i<10;i++){
		output<<randarray[i]<<" ";
	}

	output.close();

	readFile("hw01.txt");

	return 0;
}

int generateRandom(){
	return ((rand()%(899))+100);
}

int triple(int number){
	return (number*3);
}

int sum(int number){
	int first;
	int second;
	int third;

	third = number % 10;
	second = number/10 % 10;
	first = number/100 % 10;

	return third+second+first;
}

void bubbleSort(int numArray[10],int SIZE){

	int temp = 0;
	int n1 = (SIZE - 1);
	int n2 = 0;
	int i =	0;
	while(n1 > 0) { //while there are still numbers to sort
		n2	=	n1; //get index of current value
		i	=	0;
		while(n2 > 0) { //begin comparisons
			temp	=	numArray[i]; //store current number in temp variable
			if(temp > numArray[i+1]) { //if the current value is greater than the next in the list, swap them
				numArray[i]	=	numArray[i+1]; 
				numArray[i+1]	=	temp;
			}
			i++;
			n2--;
		}
		n1--;
	}

	return;
}

void print(int theArray[10]){
	for(int i=0;i<10;i++){
		cout<<theArray[i]<<" ";
	}
	cout<<endl;
	return;
}

void readFile(string filename){
	ifstream input;
	input.open(filename);
	int i=0;
	int tempArray[10];
	for(i=0;i<10;i++){
		input >> tempArray[i];
	}
	input.close();
	print(tempArray);
	return;
}