#include "inventory.h"

mgmt::ManageInventory::~ManageInventory(){
	int i;
	for(i = 0; i < count; i++){
		delete p_pInventoryItems[i];
	}
	for(i=0; i<transactCount; i++){
		delete p_pTransactions[i];
	}
	delete [] p_pTransactions;
	delete [] p_pInventoryItems;
}

void mgmt::ManageInventory::addItem(string name, int quantity, float cost){
	p_pInventoryItems[count] = new Item;
	p_pInventoryItems[count]->name = name;
	p_pInventoryItems[count]->quantity = quantity;
	p_pInventoryItems[count]->cost = cost;
	count++;
}

void mgmt::ManageInventory::printInventory() const{
	for(int i=0;i<count;i++){
		cout <<(i+1)<<". "<<"Item: "<<p_pInventoryItems[i]->name<<"  "
			<<"Quantity: "<<p_pInventoryItems[i]->quantity<<"  "
			<<"Cost: $"<<p_pInventoryItems[i]->cost<<endl;	
	}
}

void mgmt::ManageInventory::addItemToTransaction(int item,int quantity){
	item--;
	p_pInventoryItems[item]->quantity -= quantity;
	p_pTransactions[transactCount]->addOrderItem(p_pInventoryItems[item],quantity);
}

int mgmt::ManageInventory::getCount() const{
	return count;
}

int mgmt::ManageInventory::getTransactionCount() const{
	return transactCount;
}

void mgmt::ManageInventory::incrementTransactionCount(){
	transactCount++;
}

void mgmt::ManageInventory::setTransactionName(string n){
	p_pTransactions[transactCount] = new Transaction;
	p_pTransactions[transactCount]->setName(n);
}

mgmt::Transaction ** mgmt::ManageInventory::getTransactionPointer() const{
	return p_pTransactions;
}

void mgmt::ManageInventory::printTransactionHistory() const{
	for(int i=0;i<transactCount;i++){
		cout <<endl<<endl<<(i+1)<<". "<<"Name: "<<p_pTransactions[i]->getName();
		cout <<endl<<endl<<"-----------------Order items-----------------"<<endl<<endl;
		p_pTransactions[i]->printItems();
	}
}

//---------------------------------the following function definitions are for extra credit transaction history--------------------------

int mgmt::Transaction::getItemCount() const{
	return itemCount;
}

void mgmt::Transaction::printItems() const{
	for(int i=0;i<itemCount;i++){
		cout <<left<<setw(20)<<p_pOrderItems[i]->name<<"  "<<setw(5)<<p_pOrderItems[i]->quantity <<"  $"<<p_pOrderItems[i]->cost<<endl;
		cout <<"_____________________________________________"<<endl;
	}
	cout << "Before Tax: $"<<getBeforeTax()<<"   "<<"Total: $"<<getTotal()<<endl;
}

float mgmt::Transaction::getTotal() const{
	return totalCost;
}

float mgmt::Transaction::getBeforeTax() const{
	return beforeTax;
}

void mgmt::Transaction::computeTotal(){
	for(int i=0;i<itemCount;i++){
		beforeTax += ((p_pOrderItems[i]->cost)*(p_pOrderItems[i]->quantity));
	}
	totalCost = beforeTax + (beforeTax * (0.0825));
}

void mgmt::Transaction::setName(string n){
	name = n;
}

string mgmt::Transaction::getName() const{
	return name;
}

void mgmt::Transaction::addOrderItem(Item * newItem,int quantity){
	p_pOrderItems[itemCount] = new Item;
	p_pOrderItems[itemCount]->name = newItem->name;
	p_pOrderItems[itemCount]->quantity = quantity;
	p_pOrderItems[itemCount]->cost = newItem->cost;
	itemCount++;
}

mgmt::Transaction::~Transaction(){
	for(int i=0; i<itemCount; i++){
		delete p_pOrderItems[i];
	}
	delete [] p_pOrderItems;
}