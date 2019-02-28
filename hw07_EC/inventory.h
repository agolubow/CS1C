#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <iostream>
#include <string>

using namespace std;

//namespace mgmt{

const int MAX_SIZE = 50;

	struct Item{

		string name;
		int quantity;
		float cost;

	};

	class ManageInventory{
		public:
			ManageInventory() : count{0}, p_pInventoryItems {new Item*[size]} { }
			ManageInventory(int size) : size{size}, count{0}, p_pInventoryItems {new Item*[size]} { }
			~ManageInventory();
			void addItem(string name, int quantity, float cost);
			void print();
		private:
			int size {MAX_SIZE};
			int count;
			Item ** p_pInventoryItems;
	};

//}

#endif