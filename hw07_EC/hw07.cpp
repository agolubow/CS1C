#include "inventory.h"

int main(){

	ManageInventory inventory(5);
	inventory.addItem("Nike basketball shoes",22,145.99);
	inventory.addItem("Under Armour T-shirt",33,29.99);
	inventory.addItem("Brooks running shoes",11,111.44);
	inventory.addItem("Asics running shoes",20,165.88);
	inventory.addItem("Nike shorts",77,45.77);
	inventory.print();

	return 0;
}