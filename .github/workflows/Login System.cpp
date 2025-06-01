// Aotearoa Treasures LogIn System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define user structure to store login information and roles
struct User {
    string username;
    string pin;
    string role;      // "CUSTOMER", "ADMIN", "STAFF"
    string location;  // only for ADMINs and STAFF
};

// Predefined list of users
vector<User> users = {
    {"john", "123456", "CUSTOMER", ""},
    {"lucy", "234567", "CUSTOMER", ""},
    {"admin1", "0001", "ADMIN", "Wellington"},
    {"admin2", "0002", "ADMIN", "Christchurch"},
    {"admin3", "0003", "ADMIN", "Auckland"},
    {"staff1", "1111", "STAFF", "Wellington"},
    {"staff2", "2222", "STAFF", "Christchurch"},
    {"staff3", "3333", "STAFF", "Auckland"}
};

// Function to authenticate user by username and PIN
User* authenticate(const string& username, const string& pin) {
    for (auto& user : users) {
        if (user.username == username && user.pin == pin) {
            return &user; // Return pointer to user if match found
        }
    }
    return nullptr; // Return null pointer if not found
}

// Display menu for customer
void showCustomerMenu() {
    cout << "\n[Customer Portal]\n";
    cout << "1. Browse Products\n";
    cout << "2. Place Order\n";
    cout << "3. Exit\n";
}

// Display menu for admin, based on location
void showAdminMenu(const string& location) {
    cout << "\n[Admin Portal - " << location << "]\n";
    cout << "1. Manage Inventory\n";
    cout << "2. Manage Staff\n";
    cout << "3. Exit\n";
}

// Display menu for staff, based on location
void showStaffMenu(const string& location) {
    cout << "\n[Staff Portal - " << location << "]\n";
    cout << "1. View Roster\n";
    cout << "2. Mark Attendance\n";
    cout << "3. Exit\n";
}

int main() {
    string username, pin;

    // Prompt user for login
    cout << "=== Aotearoa Treasures Login ===\n";
    cout << "Username: ";
    cin >> username;
    cout << "PIN: ";
    cin >> pin;

    // Authenticate user
    User* user = authenticate(username, pin);

    // Check login success
    if (!user) {
        cout << "\nInvalid login. Please try again.\n";
        return 0;
    }

    // Role-based access
    if (user->role == "CUSTOMER") {
        if (pin.length() != 6) {
            cout << "\nInvalid customer PIN length. Expected 6 digits.\n";
            return 0;
        }
        showCustomerMenu();
    }
    else if (user->role == "ADMIN") {
        if (pin.length() != 4) {
            cout << "\nInvalid admin PIN length. Expected 4 digits.\n";
            return 0;
        }
        showAdminMenu(user->location);
    }
    else if (user->role == "STAFF") {
        if (pin.length() != 4) {
            cout << "\nInvalid staff PIN length. Expected 4 digits.\n";
            return 0;
        }
        showStaffMenu(user->location);
    }
    else {
        cout << "\nUnknown role.\n";
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
