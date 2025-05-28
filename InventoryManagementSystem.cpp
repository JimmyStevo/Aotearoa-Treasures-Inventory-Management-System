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

int main() {


	//setting vectors up for use with the structure
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
	int iInvChoice = 0;
	string sItemSelect;
	int i = 0;


	cout << "Select an option: ";

	// Set a do while loop to keep the main selection present until breaking out of it for user choices in the switch cases themselves
	do {

		cout << "\n1. Change Stock of an Item.\n2. Change the price of an Item.\n3. Change Item Name.\n4. Add a new item.\n5. Remove an Item.\n6. Return to previous screen.\n7. Exit\n";
		cin >> iInvChoice;

		cin.ignore();

		switch (iInvChoice) {
		case 1:
			//for loop to list out the current stock, accounts for potentiall increased / decreased vector
			for (int i = 0; i < iInv.size(); ++i) {
				cout << iInv[i].sItemName << " \t " << iInv[i].iStock << "\t" << iInv[i].dPrice << "\n";
			}
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
				cout << "succuss" << endl;
			}
			else {
				cout << "Enter a valid selection!\n";
			}

			iInv[i].iStock = UpdateStock(iInv[i].iStock);

			cout << iInv[i].iStock;

			break;
		case 2:
			//for loop to list out the current stock, accounts for potentiall increased / decreased vector
			for (int i = 0; i < iInv.size(); ++i) {
				cout << iInv[i].sItemName << " \t " << iInv[i].iStock << "\t" << iInv[i].dPrice << "\n";
			}
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
	} while (iInvChoice != 7);
};

