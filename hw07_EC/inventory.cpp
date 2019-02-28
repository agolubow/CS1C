#include "inventory.h"

ManageInventory::~ManageInventory(){
	for(int i = 0; i < count; i++){
		delete p_pInventoryItems[i];
	}
	delete [] p_pInventoryItems;
}

void ManageInventory::addItem(string name, int quantity, float cost){
	p_pInventoryItems[count] = new Item;
	p_pInventoryItems[count]->name = name;
	p_pInventoryItems[count]->quantity = quantity;
	p_pInventoryItems[count]->cost = cost;
	count++;
}

void ManageInventory::print(){
	for(int i=0;i<count;i++){
		cout << "----Item "<<(i+1)<<"----"<<endl
			<<"Name: "<<p_pInventoryItems[i]->name<<endl
			<<"Quantity: "<<p_pInventoryItems[i]->quantity<<endl
			<<"Cost: $"<<p_pInventoryItems[i]->cost<<endl<<endl;
	}
}