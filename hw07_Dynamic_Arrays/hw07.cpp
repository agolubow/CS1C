#include "inventory.h"

int main(){

	char answer = 'y';
	int item;
	int quantity = 0;
	string customer;
	cout<<fixed<<setprecision(2);
	mgmt::ManageInventory * inventory;
	inventory = new mgmt::ManageInventory(5);

	inventory->addItem("Nike basketball shoes",22,145.99);
	inventory->addItem("Under Armour T-shirt",33,29.99);
	inventory->addItem("Brooks running shoes",11,111.44);
	inventory->addItem("Asics running shoes",20,165.88);
	inventory->addItem("Nike shorts",77,45.77);
	
	cout <<endl<<"----------Inventory before transaction----------"<<endl<<endl;
	inventory->printInventory();

	cout <<endl<<"Please Enter your name: ";
	cin >> (customer);
	inventory->setTransactionName(customer);
	do{
		inventory->printInventory();
		cout <<endl<<endl<<"Please enter the number of the item you wish to purchase: ";
		cin >> item;
		cout <<"Please enter the quantity you wish to purchase: ";
		cin >> quantity;
		inventory->addItemToTransaction(item,quantity);
		cout <<endl<<"Would you like to add another item to your order? (Y/N): ";
		cin >> answer;
		cout<<endl;

	}while(answer != 'n' && answer != 'N');

	cout <<endl<<"----------------RECEIPT----------------"<<endl<<endl;
	inventory->getTransactionPointer()[inventory->getTransactionCount()]->computeTotal();
	inventory->getTransactionPointer()[inventory->getTransactionCount()]->printItems();
	inventory->incrementTransactionCount();

	//extra credit portion

	inventory->setTransactionName("Alex");
	inventory->addItemToTransaction(3,2);
	inventory->addItemToTransaction(5,3);
	inventory->getTransactionPointer()[inventory->getTransactionCount()]->computeTotal();
	inventory->incrementTransactionCount();
	
	cout <<endl<<endl<<"----------------EXTRA CREDIT-----------------"<<endl<<endl;
	inventory->printTransactionHistory();

	return 0;
}