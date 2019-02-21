#include "hw06.h"

int main(){

	int begin = 0;
	int end = 0;
	string alphabet;
	cout <<endl<<"Please enter a string: ";
	getline(cin,alphabet);
	cout << "Please enter the first index: ";
	while(!(cin>>begin)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "Please enter the first index: ";
	}
	cout << "Please enter the second index: ";
	while(!(cin>>end)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "Please enter second index: ";
	}
	string reversed = reverse(begin,end,alphabet);
	cout <<endl<<reversed<<endl<<endl;
	cout << "Please enter the first index: ";
	while(!(cin>>begin)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "Please enter the first index: ";
	}
	cout << "Please enter the second index: ";
	while(!(cin>>end)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "Please enter second index: ";
	}
	reversed = reverse(begin,end,alphabet);
	cout <<endl<<reversed<<endl<<endl;
	reversed = reverse(0,25,alphabet);
	cout <<"--Total reversal--"<<endl<<reversed<<endl<<endl;

	//begin extra credit

	cout<<endl<<"--------EXTRA CREDIT BONUS ROUND--------"<<endl<<endl;

	cout << "Please enter the first index: ";
	while(!(cin>>begin)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "Please enter the first index: ";
	}
	cout << "Please enter the second index: ";
	while(!(cin>>end)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "Please enter second index: ";
	}
	reversed = reverseLoop(begin,end,alphabet);
	cout <<endl<<reversed<<endl<<endl;
	cout << "Please enter the first index: ";
	while(!(cin>>begin)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "Please enter the first index: ";
	}
	cout << "Please enter the second index: ";
	while(!(cin>>end)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "Please enter second index: ";
	}
	reversed = reverseLoop(begin,end,alphabet);
	cout <<endl<<reversed<<endl<<endl;
	reversed = reverseLoop(0,25,alphabet);
	cout <<"--Total reversal--"<<endl<<reversed<<endl<<endl;

	return 0;
}

string reverse(int begin,int end,string str){
	swap(str[begin],str[end]);
	begin++;
	end--;
	string toReturn = str;
	if(begin < end){
		toReturn = reverse(begin,end,str);
	}
	return toReturn;
}
//extra credit use loop to reverse string
string reverseLoop(int begin,int end,string str){
	while(begin < end){
		swap(str[begin],str[end]);
		begin++;
		end--;
	}
	return str;
}