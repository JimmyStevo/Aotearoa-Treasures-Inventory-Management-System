#include <iostream>
#include <vector>
#include <string>

using namespace std;

//setting structure to house vectors for editing stock numbers / prices and adding new / removing old items
struct MyInv {
	string sItemName;
	int iStock;
	double dPrice;
};

int main() {
	//setting vectors up for use with the structure
	vector<MyInv> iInv{
		{"Mahuka Honey", 20, 1000.00},
		{"Jade Stones", 20, 200.50},
		{"Kiwi Plushie", 50, 25.00},
		{"All Blacks Jersey", 6, 60.00},
		{"Black Caps Jersey", 34, 55.00},
		{"Stickers", 100, 5.75},
		{"Magnets", 75, 6.95},
		{"Books", 39, 12.50},
		{"Stationary Bundle", 42, 35.25},
		{"ALcohol", 17, 80.64}
	};
	int iInvChoice = 0;
	int iCount = 0;
	int i = 0;
	int sItemSelect = 0;

	while (i != 1) {
		cout << "Select an option: ";
		cout << "\n1. Change Stock of an Item.\n2. Change the price of an Item.\n3. Change Item Name.\n4. Add a new item.\n5. Remove an Item.\n6. Return to previous screen.\n7. Exit";
		cin >> iInvChoice;

		switch (iInvChoice) {
		case 1:
			for (int i = 0; i > 1; i++) {
				cout << "\nWhich item would you like to edit?\n";


				cin >> sItemSelect;
			}
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
			cout << "\nPlease select an option from 1 - 7.";
		}
	}
};