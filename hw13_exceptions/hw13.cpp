#include "hw13.h"

int main(){

	queue<int> intQ;
	int * fail = nullptr;
	int * pass = new int(5);

	cout <<endl<<endl<<"---------Testing dequeue from empty queue---------"<<endl<<endl;

	try{
		intQ.dequeue();
	}catch(const underflow_error& e){
		cout << "Underflow Error: "<<e.what()<<endl<<endl;
	}

	for(int i=0;i<queueSize;i++){
		intQ.enqueue(i);
	}

	cout << "------------Testing enqueue to full queue------------"<<endl<<endl;

	try{
		intQ.enqueue(10);
	}catch(const out_of_range& e){
		cout << "Out_of_range Error: "<<e.what()<<endl<<endl;
	}

	cout << "---------Testing pass and fail of assert macro---------"<<endl<<endl;

	assert(pass != nullptr);
	assert(fail != nullptr);

	return 0;
}