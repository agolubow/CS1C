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
	inventory->printInventory();

	cout << "Please Enter your name: ";
	cin >> (customer);
	inventory->setTransactionName(customer);
	do{
		inventory->printInventory();
		cout <<"Please enter the number of the item you wish to purchase: ";
		cin >> item;
		cout <<"Please enter the quantity you wish to purchase: ";
		cin >> quantity;
		inventory->addItemToTransaction(item,quantity);

	}while(answer != 'n' && answer != 'N');

	return 0;
}