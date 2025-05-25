#include <iostream>
#include <vector>

//setting structure to house vectors for editing stock numbers / prices and adding new / removing old items
struct Inventory {
	vector<int> iStock;
	vector<string> sItemName;
	vector<double> dPrice;
};

int main{
	int iInvChoice;
	while (i != 1) {
		cout << "Select an option: ";
		cout << "\n1. Change Stock of an Item.\n2. Change the price of an Item.\n3. Change Item Name.\n4. Add a new item.\n5. Remove an Item.\n6. Return to previous screen.\n7. Exit";
		cin >> iInvChoice;

		switch (iInvChoice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			return 0;
			break;
		default:
			cout << "\nPlease select an option from 1 - 7."
		}
	}
}