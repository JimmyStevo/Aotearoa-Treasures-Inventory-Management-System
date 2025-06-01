#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

//setting structure to house vectors for editing stock numbers / prices and adding new / removing old items
struct MyInv {
	string sItemName;
	int iStock;
	double dPrice;
};

vector<MyInv> iInv{
{"MAHUKA HONEY", 20, 1000.00},
{"JADE STONES", 20, 200.50},
{"KIWI PLUSHIE", 50, 25.00},
{"ALL BLACKS JERSEY", 6, 60.00},
{"BLACK CAP JERSEY", 34, 55.00},
{"STICKERS", 100, 5.75},
{"MAGNETS", 75, 6.95},
{"BOOKS", 39, 12.50},
{"STATIONARY", 42, 35.25},
{"ALCOHOL", 17, 80.64}
};

vector<MyInv>::iterator it; // set up iterator to later be able to loop through vectors and delete / add items

// function to update the amount of stock from an Admin side
int UpdateStock(int iStockUpdate) {
	cout << "Please enter the new stock amount:\n";
	cin >> iStockUpdate;
	cin.ignore();

	return iStockUpdate;
	// add error handling here!!!! should only detect integers!!!!!
};

// function for updating the price of the stored items in the vector
double UpdatePrice(double dPriceUpdate) {
	cout << "Please enter the new price;\n";
	cin >> dPriceUpdate;
	cin.ignore();

	return dPriceUpdate;
	// add error handling here!!!! should only detect doubles!!!!!

};

string ChangeName(string sChangeName) {
	sChangeName = "Ting";
	return sChangeName;
};

void AddNew();

void Remove();

void ConvertString(string& s) {
	for (int i = 0; i < s.length(); ++i) {
		s[i] = toupper(s[i]);
	}
}

void DisplayProducts() {
	cout << "Products listed at wellington:\n";
	cout << setw(20) << "Name" << setw(15) << "Stock" << setw(20) << "Price" << "\n";
	for (auto& MyInv : iInv) {
		cout << setw(20) << MyInv.sItemName << setw(15) << MyInv.iStock << setw(20) << MyInv.dPrice << "\n";
	}

}

int main() {


	//setting vectors up for use with the structure



	int iInvChoice = 0;
	string sItemSelect;
	int i = 0;
	int iAddInv;
	double dAddPrice;



	cout << "Select an option: ";

	// Set a do while loop to keep the main selection present until breaking out of it for user choices in the switch cases themselves
	do {

		cout << "\n1. Change Stock of an Item.\n2. Change the price of an Item.\n3. Change Item Name.\n4. Add a new item.\n5. Remove an Item.\n6. Return to previous screen.\n7. Exit\n";
		cin >> iInvChoice;

		cin.ignore();

		switch (iInvChoice) {
		case 1:
			//call function to list out the stock with their prices

			DisplayProducts();

			cout << "\nWhich item would you like to edit?\n" << endl;
			getline(cin, sItemSelect);



			ConvertString(sItemSelect);
			cout << sItemSelect << endl;

			i = 0;

			while (iInv[i].sItemName != sItemSelect) {
				i++;
				// add error handling here!!!!
				//@@
			};
			if (iInv[i].sItemName == sItemSelect) {
				cout << "success" << endl;
			}
			else {
				cout << "Enter a valid selection!\n";
			}

			iInv[i].iStock = UpdateStock(iInv[i].iStock);

			cout << iInv[i].iStock;

			break;
		case 2:
			//call function to list out the stock with their prices

			DisplayProducts();
			cout << "\nWhich item would you like to edit?\n" << endl;
			getline(cin, sItemSelect);



			ConvertString(sItemSelect);
			cout << sItemSelect << endl;

			i = 0;

			while (iInv[i].sItemName != sItemSelect) {
				i++;
				// add error handling here!!!!
				//@@
			};
			if (iInv[i].sItemName == sItemSelect) {
				cout << "succuss";
			}
			else {
				cout << "Enter a valid selection!";
			}

			iInv[i].dPrice = UpdatePrice(iInv[i].dPrice);

			cout << iInv[i].dPrice;
			break;
		case 3:
			break;
		case 4:
			cout << "\nEnter a Product Name\n" << endl;
			getline(cin, sItemSelect);


			cout << "\nEnter the Amount of stock for the product:\n" << endl;
			cin >> iAddInv;


			cout << "\nEnter the Price of the product:\n" << endl;
			cin >> dAddPrice;

			iInv.push_back({ sItemSelect, iAddInv, dAddPrice });

			DisplayProducts();

			break;
		case 5: //case for removing an item in the vector
			DisplayProducts();
			cout << "what would you like to remove?:" << endl;
			getline(cin, sItemSelect);

			ConvertString(sItemSelect);

			//for loop using the iterator to iterate through the vector to then remove an item
			for (auto it = iInv.begin(); it != iInv.end(); ) {
				if (it->sItemName == sItemSelect) {
					it = iInv.erase(it);
				}
				else {
					++it;
				}
			}

			break;
		case 6:
			break;
		case 7:
			return 0;
			break;
		default:
			cout << "\nPlease select an option from 1 - 7.";
		}
	} while (iInvChoice != 7);
};

