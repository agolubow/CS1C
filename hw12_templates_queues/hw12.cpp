#include "hw12.h"

int main(){

	queue<int> intQ;
	queue<double> doubleQ;
	queue<string> stringQ;

	cout <<"-----------Testing isEmpty()-----------"<<endl<<endl;

	if(intQ.isEmpty()){
		cout << "queue is empty!"<<endl<<endl;
	}else{
		cout << "queue isn't empty!"<<endl<<endl;
	}

	cout <<"-----------Testing isFull()-----------"<<endl<<endl;

	if(doubleQ.isFull()){
		cout << "queue is full!"<<endl<<endl;
	}else{
		cout << "queue isn't full!"<<endl<<endl;
	}

	cout << "-----------BEGINNING INSERTIONS----------"<<endl<<endl;

	for(int i = 0;i < 6; i++){
		intQ.enqueue(i+1);
		cout <<"-----------int queue-----------"<<endl<<endl;
		intQ.print();
		doubleQ.enqueue(i+0.5);
		cout <<"-----------double queue-----------"<<endl<<endl;
		doubleQ.print();
	}
	stringQ.enqueue("string_one");
	cout <<"-----------string queue-----------"<<endl<<endl;
	stringQ.print();
	stringQ.enqueue("string_two");
	cout <<"-----------string queue-----------"<<endl<<endl;
	stringQ.print();
	stringQ.enqueue("string_three");
	cout <<"-----------string queue-----------"<<endl<<endl;
	stringQ.print();
	stringQ.enqueue("string_four");
	cout <<"-----------string queue-----------"<<endl<<endl;
	stringQ.print();
	stringQ.enqueue("string_five");
	cout <<"-----------string queue-----------"<<endl<<endl;
	stringQ.print();
	stringQ.enqueue("string_six");
	cout <<"-----------string queue-----------"<<endl<<endl;
	stringQ.print();

	cout <<"-----------Testing isEmpty() after adding to queues-----------"<<endl<<endl;

	if(intQ.isEmpty()){
		cout << "queue is empty!"<<endl<<endl;
	}else{
		cout << "queue isn't empty!"<<endl<<endl;
	}

	cout << "-----------BEGINNING DELETIONS----------"<<endl<<endl;

	for(int j = 0;j < 4;j++){
		intQ.dequeue();
		cout <<"-----------int queue-----------"<<endl<<endl;
		intQ.print();
		doubleQ.dequeue();
		cout <<"-----------double queue-----------"<<endl<<endl;
		doubleQ.print();
		stringQ.dequeue();
		cout <<"-----------string queue-----------"<<endl<<endl;
		stringQ.print();
	}

	cout << "-----------BEGINNING INSERTIONS pt.2----------"<<endl<<endl;

	for(int m = 0;m < 5; m++){
		intQ.enqueue((m+10));
		cout <<"-----------int queue-----------"<<endl<<endl;
		intQ.print();
		doubleQ.enqueue((m+10.5));
		cout <<"-----------double queue-----------"<<endl<<endl;
		doubleQ.print();
	}

	stringQ.enqueue("string_seven");
	cout <<"-----------string queue-----------"<<endl<<endl;
	stringQ.print();
	stringQ.enqueue("string_eight");
	cout <<"-----------string queue-----------"<<endl<<endl;
	stringQ.print();
	stringQ.enqueue("string_nine");
	cout <<"-----------string queue-----------"<<endl<<endl;
	stringQ.print();
	stringQ.enqueue("string_ten");
	cout <<"-----------string queue-----------"<<endl<<endl;
	stringQ.print();
	stringQ.enqueue("string_eleven");
	cout <<"-----------string queue-----------"<<endl<<endl;
	stringQ.print();

	cout <<"-----------Testing isFull() after filling queues-----------"<<endl<<endl;

	if(doubleQ.isFull()){
		cout << "queue is full!"<<endl<<endl;
	}else{
		cout << "queue isn't full!"<<endl<<endl;
	}

	cout << "-----------BEGINNING DELETIONS pt.2----------"<<endl<<endl;

	for(int l = 0;l < 3;l++){
		intQ.dequeue();
		cout <<"-----------int queue-----------"<<endl<<endl;
		intQ.print();
		doubleQ.dequeue();
		cout <<"-----------double queue-----------"<<endl<<endl;
		doubleQ.print();
		stringQ.dequeue();
		cout <<"-----------string queue-----------"<<endl<<endl;
		stringQ.print();
	}

	cout << "-----------TESTING front() of string queue-----------"<<endl<<endl;
	cout<<"the front is: "<<stringQ.front()<<endl<<endl;

	return 0;
}