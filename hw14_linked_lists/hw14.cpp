#include "hw14.h"

int main(){

	LinkedList<int> intlistOne;

	for(int i=0;i<5;i++){
		intlistOne.insertLast((i*10));
	}

	cout << "----Printing first list----"<<endl<<endl;
	intlistOne.print();

	cout << "----testing copy constructor----"<<endl<<endl;
	LinkedList<int> intlistTwo(intlistOne);
	intlistTwo.print();

	cout << "----testing copy assignment----"<<endl<<endl;
	LinkedList<int> intlistThree = intlistOne;
	intlistThree.print();

	cout << "----testing reverse list----"<<endl<<endl;
	LinkedList<int> intreverse;
	intreverse.LinkedListReverse(intlistOne);
	intreverse.print();

	cout << "----testing delete from empty----"<<endl<<endl;
	LinkedList<int> intempty;
	try{
		intempty.deleteNode(3);
	}catch(const underflow_error& e){
		cout<<"underflow error: "<<e.what()<<endl;
	}

	cout << "----testing delete does not exist----"<<endl<<endl;
	intlistOne.deleteNode(100);

	cout << "----testing deleting nodes----"<<endl<<endl;
	intlistOne.deleteNode(20);
	intlistTwo.deleteNode(20);
	intlistOne.print();
	intlistTwo.print();

	cout << "----testing adding to middle----"<<endl<<endl;

	intlistOne.insertmiddle(50);
	intlistTwo.insertmiddle(60);

	intlistOne.print();
	intlistTwo.print();

	cout<<"------------BEGIN DOUBLES PORTION-----------"<<endl<<endl;

	LinkedList<double> doublelistOne;

	for(int j=0;j<5;j++){
		doublelistOne.insertLast((j*10)+0.5);
	}

	cout << "----Printing first list----"<<endl<<endl;
	doublelistOne.print();

	cout << "----testing copy constructor----"<<endl<<endl;
	LinkedList<double> doublelistTwo(doublelistOne);
	doublelistTwo.print();

	cout << "----testing copy assignment----"<<endl<<endl;
	LinkedList<double> doublelistThree = doublelistOne;
	doublelistThree.print();

	cout << "----testing reverse list----"<<endl<<endl;
	LinkedList<double> doublereverse;
	doublereverse.LinkedListReverse(doublelistOne);
	doublereverse.print();

	cout << "----testing delete from empty----"<<endl<<endl;
	LinkedList<double> doubleempty;
	try{
		doubleempty.deleteNode(3.5);
	}catch(const underflow_error& h){
		cout<<"underflow error: "<<h.what()<<endl;
	}

	cout << "----testing delete does not exist----"<<endl<<endl;
	doublelistOne.deleteNode(100.5);

	cout << "----testing deleting nodes----"<<endl<<endl;
	doublelistOne.deleteNode(20.5);
	doublelistTwo.deleteNode(20.5);
	doublelistOne.print();
	doublelistTwo.print();

	cout << "----testing adding to middle----"<<endl<<endl;

	doublelistOne.insertmiddle(50.5);
	doublelistTwo.insertmiddle(60.5);

	doublelistOne.print();
	doublelistTwo.print();

	return 0;
}