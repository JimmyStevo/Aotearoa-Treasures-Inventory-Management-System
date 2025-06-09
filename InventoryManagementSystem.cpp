// Inventory System Refactor.cpp : This file contains the 'main' function. Program execution begins and ends there.

//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

//Setup of class for the inventory base to be inherited by other classes
class Inventory {
public:
    string name;
    int stock;
    double price;

    //function to prompt the user for inventory specific variables and store them
    void input() {

        cout << "Enter the item name:\n";
        getline(cin, name);
        cout << "Enter the price:\n";
        cin >> price;
        cout << "Enter the amount of stock:\n";
        cin >> stock;
        cin.ignore();
    }
};

// class set up for vector usage to hold item information and functions related to the 
class item {
private:
    // function to convert strings to upper case for comparison purposes
    void ConvertString(string& s) {
        for (int i = 0; i < s.length(); ++i) {
            s[i] = toupper(s[i]);
        }
    }
public:
    //sets vector for the use of items in a location
    vector<Inventory> vInv{
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

    vector<Inventory>::iterator it;

    //function to add new stock to the vector using the base class of Inventory to prompt the user questions
    void addStock() {
        Inventory Stock;
        Stock.input();
        vInv.push_back(Stock);
    }

    //iterator to display the table of items for the location specified
    void display() {
        cout << "Products listed at wellington:\n";
        cout << setw(20) << "Name" << setw(15) << "Stock" << setw(20) << "Price" << "\n";
        for (auto& Inventory : vInv) {
            cout << setw(20) << Inventory.name << setw(15) << Inventory.stock << setw(20) << fixed << setprecision(2) << Inventory.price << "\n";
        }
    }

    // function to grab the name of the item to update the stock, then update stock with a legitimate number / integer
    void stockcheck(int iStock, int iNumber) {

        if (iStock < 5) {
            cout << vInv[iNumber].name << " needs to be restocked";
        }
        else {
            cout << "Current stock of " << vInv[iNumber].name << " is " << vInv[iNumber].stock << endl;
        }
    }



    //function for selecting an item, allows for multiple selection to then direct to the correct function after
    string SelectItem() {
        string sUpdate;
        display();

        cout << "Which item would you like to update?";
        getline(cin, sUpdate);
        return sUpdate;

    }

    void ChangeStockName(string s) {
        string sNewName, tempname;
        ConvertString(s);

        for (auto& Inventory : vInv) {
            tempname = Inventory.name;
            ConvertString(tempname);

            if (tempname == s) {
                cout << "What would you like the new name to be?\n";
                getline(cin, sNewName);
                Inventory.name = sNewName;
            }
        }
    }
    // functionb using an iterator to find the parsed item name and delete it from the records
    void RemoveItem(string s) {
        ConvertString(s);
        for (auto it = vInv.begin(); it != vInv.end(); ) {
            if (it->name == s) {
                it = vInv.erase(it);
                cout << "removed successfully";
            }
            else {
                ++it;
            }
        }

    }

    void UpdateItemPrice(string s) {
        ConvertString(s);

    }

    void UpdateItemStock(string s) {
        ConvertString(s);
    }
};

class UserInvSelection {
public:
    int iChoice;
    item checks;
    string sChoice;

    void SelectingOptions() {
        do {
            cout << "\n1. Add New Item.\n2. Change Item Name.\n3. Change the price of an Item.\n4. Change Stock of an Item.\n5. Remove an Item.\n6. Return to previous screen.\n7. Exit\n";
            cin >> iChoice;

            switch (iChoice) {
            case 1:
                cin.ignore();
                checks.addStock();
                break;
            case 2:
                cin.ignore();
                checks.ChangeStockName(checks.SelectItem());
                break;
            case 3:
                cin.ignore();
                checks.UpdateItemPrice(checks.SelectItem());
                break;
            case 4:
                cin.ignore();
                checks.UpdateItemStock(checks.SelectItem());
                break;
            case 5:
                cin.ignore();
                checks.RemoveItem(checks.SelectItem());
                break;
            case 6:
                cin.ignore();
                break;
            case 7:
                cin.ignore();
                break;
            default:
                cout << "Please choose a valid selection between 1 and 7!";
            }
        } while (iChoice != 7);
    }

};


int main()
{
    UserInvSelection Choose;

    Choose.SelectingOptions();
}