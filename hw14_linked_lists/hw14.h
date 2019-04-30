#ifndef HW14_H
#define HW14_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <class Type>
struct node{
	Type info;
	node<Type> *next;
	node<Type> *previous;
};

template <class Type>
class LinkedList{
public:

	LinkedList();
	LinkedList(const LinkedList<Type>&);
	~LinkedList();
	const LinkedList<Type>& operator=(const LinkedList<Type>&);
	bool isEmptyList() const;
	void print() const;
	void printReverse() const;
	int length() const;
	void destroyList();
	Type front();
	Type back();
	//bool search(nodeType *,int);
	void LinkedListReverse(const LinkedList<Type>&);
	void insertFirst(Type);
	void insertLast(Type);
	void insertmiddle(Type);
	void deleteNode(Type);
	node<Type>* getHead() const;

private:
	node<Type> *head;
	node<Type> *tail;
	int count;
};

template <class Type>
LinkedList<Type>::LinkedList(){
	head = nullptr;
	tail = nullptr;
	count = 0;
}

template <class Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>& other){ //copy constructor
	head = nullptr;
	tail = nullptr;
	count = 0;
	node<Type> *current;
	current = (other.getHead());
	while(current != nullptr){
		//cout << current->info<<" ";
		insertLast(current->info);
		current = current->next;
	}
}

template <class Type>
void LinkedList<Type>::LinkedListReverse(const LinkedList<Type>& other){ //copy constructor
	head = nullptr;
	tail = nullptr;
	count = 0;
	node<Type> *current;
	current = (other.getHead());
	while(current != nullptr){
		//cout << current->info<<" ";
		insertFirst(current->info);
		current = current->next;
	}
}

template <class Type>
const LinkedList<Type>& LinkedList<Type>::operator=(const LinkedList<Type>& other){
	destroyList();
	head = nullptr;
	tail = nullptr;
	count = 0;
	node<Type> *current;
	current = other.getHead();
	while(current != nullptr){
		insertLast(current->info);
		current = current->next;
	}
	//count = other.length();
	return *this;
}

template <class Type>
LinkedList<Type>::~LinkedList(){
	destroyList();
}

template <class Type>
bool LinkedList<Type>::isEmptyList() const{
	return (head == nullptr);
}

template <class Type>
int LinkedList<Type>::length() const{
	return count;
}

template <class Type>
void LinkedList<Type>::destroyList(){
	node<Type> *temp;
	while (head != nullptr){
		temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
	count = 0;
	return;
}

template <class Type>
Type LinkedList<Type>::front(){
	return head->info;
}

template <class Type>
Type LinkedList<Type>::back(){
	return tail->info;
}

template <class Type>
node<Type>* LinkedList<Type>::getHead() const{
	return head;
}

// template <class Type>
// bool LinkedList<Type>::search(nodeType *head,int target){
// 	bool found = false;
// 	nodeType* current;
// 	current = head;

// 	while(!found && (current != nullptr)){
// 		if(current->info == target){
// 			found = true;
// 		}else{
// 			current = current->next;
// 		}
// 	}
// 	return found;
// }

template <class Type>
void LinkedList<Type>::insertFirst(Type newItem){
	node<Type> *newNode = new node<Type>;
	newNode->info = newItem;
	newNode->next = nullptr;
	newNode->previous = nullptr;

	if(isEmptyList()){
		head = newNode;
		tail = newNode;
	}else{
		newNode->next = head;
		head->previous = newNode;
		head = newNode;
	}
	count++;
	return;
}

template <class Type>
void LinkedList<Type>::insertLast(Type newItem){
	node<Type> *newNode = new node<Type>;
	newNode->info = newItem;
	newNode->next = nullptr;
	newNode->previous = nullptr;

	if(isEmptyList()){
		head = newNode;
		tail = newNode;
	}else{
		newNode->previous = tail;
		tail->next = newNode;
		tail = newNode;
	}
	count++;
	return;
}

template <class Type>
void LinkedList<Type>::insertmiddle(Type newItem){
	node<Type> *newNode = new node<Type>;
	node<Type> *temp = head;
	newNode->info = newItem;
	newNode->next = nullptr;
	newNode->previous = nullptr;

	if(isEmptyList()){
		head = newNode;
		tail = newNode;
	}else{
		int middle = ((count/2));
		int i=1;
		while(i<middle){
			temp = temp->next;
			i++;
		}
		newNode->previous = temp;
		newNode->next = temp->next;
		temp->next = newNode;
	}
	count++;
	return;
}

template <class Type>
void LinkedList<Type>::deleteNode(Type deleteItem){
	node<Type> *current;
	node<Type> *trail;
	bool found;
	int nodeNumber = 1;

	if(head == nullptr){
		throw underflow_error("Cannot delete from an empty list");
	}else{
		if(head->info == deleteItem){
			current = head;
			head = head->next;
			count--;
			if(head == nullptr){
				tail = nullptr;
			}
			delete current;

		}else{
			found = false;
			trail = head;
			current = head->next;
			while(current != nullptr && !found){
				if(current->info != deleteItem){
					trail = current;
					current = current->next;
					nodeNumber++;
				}else{
					found = true;
				}
			}
			if(found){
				trail->next = current->next;
				count--;
				if(tail == current){
					tail = trail;
				}
				delete current;
				cout<<deleteItem<<" (node # "<<nodeNumber<<") has been deleted"<<endl<<endl;
			}else{
				cout<<"the item to be deleted does not exists within the list"<<endl<<endl;
			}
		}
	}
}

template <class Type>
void LinkedList<Type>::print() const{
	node<Type> *current;
	current = head;
	while (current != nullptr){
		cout << current->info << " ";
		current = current->next;
	}
	cout << endl;
	return;
}

template <class Type>
void LinkedList<Type>::printReverse() const{
	node<Type> *current;
	current = tail;
	while (current != nullptr){
		cout << current->info << " ";
		current = current->previous;
	}
	cout << endl;
	return;
}

#endif