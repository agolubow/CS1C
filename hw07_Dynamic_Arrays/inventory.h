#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

namespace mgmt{

const int MAX_SIZE = 50;

	struct Item{

		string name;
		int quantity;
		float cost;

	};

	class Transaction{

	public:
		Transaction() : itemCount{0},p_pOrderItems{new Item*[5]},totalCost {0.00} {}
		~Transaction();
		int getItemCount() const;
		void printItems() const;
		void computeTotal();
		void setName(string);
		void addOrderItem(Item*,int);
		float getBeforeTax() const;
		float getTotal() const;
		string getName() const;
	private:
		string name;
		int itemCount;
		Item ** p_pOrderItems;
		float beforeTax;
		float totalCost;
	};

	class ManageInventory{
		public:
			ManageInventory() : count{0}, transactCount{0}, p_pInventoryItems {new Item*[size]}, p_pTransactions {new Transaction*[10]} { }
			ManageInventory(int size) : size{size}, count{0}, transactCount{0}, p_pInventoryItems {new Item*[size]}, p_pTransactions {new Transaction*[10]} { }
			~ManageInventory();
			void addItem(string, int, float);
			void setTransactionName(string);
			void printInventory() const;
			void printTransactionHistory() const;
			void addItemToTransaction(int,int);
			void incrementTransactionCount();
			int getCount() const;
		private:
			int size {MAX_SIZE};
			int count;
			int transactCount;
			Item ** p_pInventoryItems;
			Transaction ** p_pTransactions;
	};

}

#endif