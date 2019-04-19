#ifndef HW13_H
#define HW13_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <assert.h>

using namespace std;

const int queueSize = 7;

template <class Type>
class queue{

public:
	queue():frontIndex{0},backIndex{0},sizeOfQueue{0},array{new Type[queueSize]}{} //default constructor
	queue(const queue<Type>&);
	~queue();
	const queue<Type>& operator=(const queue<Type>&);
	void enqueue(Type);
	Type dequeue();
	Type front() const;
	int size() const;
	int getFrontIndex() const;
	int getBackIndex() const;
	Type * getArrayPointer() const;
	bool isEmpty() const;
	bool isFull() const;
	void print() const;

private:
	int frontIndex;
	int backIndex; 
	int sizeOfQueue;
	Type * array; //pointer to queue array
};

template <class Type>
queue<Type>::queue(const queue<Type>& other){ //overloaded copy constructor
	frontIndex = other.getFrontIndex();
	backIndex = other.getBackIndex();
	sizeOfQueue = other.size();
	array = new Type[queueSize];
	for(int i=frontIndex;i<sizeOfQueue;i++){
		array[i] = other.getArrayPointer()[i];
	}
}

template <class Type>
const queue<Type>& queue<Type>::operator=(const queue<Type>& other){ //overloaded copy assignment
	frontIndex = other.getFrontIndex();
	backIndex = other.getBackIndex();
	sizeOfQueue = other.size();
	for(int i=frontIndex;i<sizeOfQueue;i++){
		array[i] = other.getArrayPointer()[i];
	}
}

template <class Type>
queue<Type>::~queue(){ //destructor
	delete array;
}

template <class Type>
void queue<Type>::enqueue(Type newElement){ //adds item to queue
	if(isFull()){
		throw out_of_range("attempted to add to full queue");
	}else{
		if(isEmpty()){
			array[0] = newElement;
			sizeOfQueue++;
			backIndex++;
		}else{
			array[backIndex] = newElement;
			backIndex++;
			sizeOfQueue++;
		}
	}
}

template <class Type>
Type queue<Type>::dequeue(){ //removes item from queue
	Type temp = array[0];
	if(!(isEmpty())){
		for(int i=0;i<sizeOfQueue-1;i++){
			array[i] = array[i+1];
		}
		sizeOfQueue--;
		backIndex--;
	}else{
		throw underflow_error("attempted to remove from empty queue");
	}
	return temp;
}
//----------------------------getter functions----------------------------------
template <class Type>
Type queue<Type>::front() const{
	return array[0];
}

template <class Type>
int queue<Type>::size() const{
	return sizeOfQueue;
}

template <class Type>
int queue<Type>::getFrontIndex() const{
	return frontIndex;
}

template <class Type>
int queue<Type>::getBackIndex() const{
	return backIndex;
}

template <class Type>
Type * queue<Type>::getArrayPointer() const{
	return array;
}
//----------------------------end getter functions----------------------------------
template <class Type>
bool queue<Type>::isEmpty() const{
	return (sizeOfQueue == 0);
}

template <class Type>
bool queue<Type>::isFull() const{
	return (queueSize == sizeOfQueue);
}

template <class Type>
void queue<Type>::print() const{
	if(!isEmpty()){
		for(int i = frontIndex;i<sizeOfQueue;i++){
			cout <<array[i]<<" ";
		}
		cout <<endl<<endl;
	}else{
		cout << "queue is empty!"<<endl<<endl;
	}
}
#endif