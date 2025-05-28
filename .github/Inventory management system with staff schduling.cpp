// Inventory management system with staff schduling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

// Structure to hold staff information
struct Staff {
    std::string name;
    std::string position;
    std::string days;
    std::string time;
};

// Class to represent a store and manage its staff
class Store {
public:
    std::string location;  // Store location
    std::vector<Staff> staffList;  // List of staff in the store

    // Constructor to initialize store location
    Store(const std::string& loc) : location(loc) {}

    // Function to add a new staff member
    void addStaff() {
        std::cin.ignore();  // Ensure buffer is clear for user input
        std::string name = getInput("Enter Name: ");
        std::string position = getInput("Enter Position: ");
        std::string days = getValidDays();
        std::string time = getValidTime();

        staffList.push_back({ name, position, days, time });
        std::cout << "Staff added successfully!\n";
    }

    // Function to update an existing staff member's schedule
    void updateStaff() {
        std::cin.ignore();  // Ensure buffer is clear for user input
        std::string name = getInput("Enter Staff Name to Update: ");

        auto it = findStaff(name);  // Find the staff member
        if (it != staffList.end()) {
            std::cout << "Updating " << it->name << "'s schedule.\n";
            it->days = getValidDays();
            it->time = getValidTime();
            std::cout << "Staff updated successfully!\n";
        }
        else {
            std::cout << "Staff member not found!\n";
        }
    }

    // Function to delete a staff member
    void deleteStaff() {
        std::cin.ignore(); // Ensure buffer is clear for user input
        std::string name = getInput("Enter Staff Name to Delete: ");

        auto it = findStaff(name); // Find the staff member
        if (it != staffList.end()) {
            staffList.erase(it);
            std::cout << "Staff Deleted Successfully!\n";
        }
        else {
            std::cout << "Staff Member Not Found!\n";
        }
    }

    // Function to display all staff members
    void displayStaff() const {
        std::cout << "\nStaff at " << location << ":\n";
        std::cout << std::setw(15) << "Name"
            << std::setw(15) << "Position"
            << std::setw(20) << "Days"
            << std::setw(10) << "Time" << '\n';
        std::cout << std::string(60, '-') << '\n';
        for (const auto& staff : staffList) {
            std::cout << std::setw(15) << staff.name
                << std::setw(15) << staff.position
                << std::setw(20) << staff.days
                << std::setw(10) << staff.time << '\n';
        }
    }

private:
    //Helper function to get user input with a prompt
    std::string getInput(const std::string& prompt) {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);
        return input;
    }

    //function to validate and get correct days input
    std::string getValidDays() {
        std::string days;
        while (true) {
            days = getInput("Enter Days (e.g., Monday or Monday to Friday): ");
            if (isValidDays(days)) {
                break;
            }
            else {
                std::cout << "Invalid Days. Please Enter A Valid Day or Range.\n";
            }
        }
        return days;
    }

    // Helper function to validate the input days
    bool isValidDays(const std::string& days) {
        static const std::vector<std::string> validDays = {
            "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday",
        };

        auto isValidDay = [&](const std::string& day) {
            return std::find(validDays.begin(), validDays.end(), day) != validDays.end();
            };

        //split input string on " to " to check for ranges
        size_t pos = days.find(" to ");
        if (pos != std::string::npos) {
            std::string startDay = days.substr(0, pos);
            std::string endDay = days.substr(pos + 4);
            return isValidDay(startDay) && isValidDay(endDay);
        }
        else {
            return isValidDay(days);
        }
    }

    // Function to validate and get correct time input
    std::string getValidTime() {
        std::string time;
        while (true) {
            time = getInput("Enter Time (e.g., 9am-5pm): ");
            if (time == "9am-5pm") {
                break;
            }
            else {
                std::cout << "Invalid Time. Please Enter A Valid Time Format (e.g., 9am-5pm).\n";
            }
        }
        return time;
    }

    // Function to find a staff member by name
    std::vector<Staff> ::iterator findStaff(const std::string& name) {
        return std::find_if(staffList.begin(), staffList.end(), [&](const Staff& staff) {
            return staff.name == name;
            });
    }
};

    // Function to manage store operations with a menu
void manageStore(Store& store) {
    int choice;
    do {
        std::cout << "\nManage Store: " << store.location << "\n"
            << "1. Add Staff\n"
            << "2. Update Staff\n"
            << "3. Delete Staff\n"
            << "4. Display Staff\n"
            << "5. Return to Main Menu\n"
            << "Enter Choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: store.addStaff(); 
            break;
        case 2: store.updateStaff(); 
            break;
        case 3: store.deleteStaff();
            break;
        case 4: store.displayStaff();
            break;
        case 5: std::cout << "Returning To Main Menu.\n";
            break;
        default: std::cout << "Invalid Choice. Please Try Again\n";
            break;

        }
    } while (choice != 5);
 }
	// Main function to run the program
int main() {
    Store wellington("Welington");
    Store auckland("Auckland");
    Store christchurch("Christchurch");

    //Initial data setup for demonstration
    wellington.staffList.push_back({ "Cbum", "Manager", "Monday To Friday", "9am-5pm" });
    wellington.staffList.push_back({ "Bradley Martyn", "Staff", "Monday to Wednesday", "9am-5pm" });
    wellington.staffList.push_back({ "Shan", "Staff", "Thursday to Sunday", "9am-5pm" });

    auckland.staffList.push_back({ "Andrew Tate", "Manager", "Monday To Saturday", "9am-5am"});
    auckland.staffList.push_back({ "Christian Tate", "Staff", "Monday To Wednesday", "9am-5pm" });
    auckland.staffList.push_back({ "Bob Tate", "Staff", "Thursday To Sunday", "9am-5pm" });

    christchurch.staffList.push_back({ "John Key", "Manager", "Monday To Friday", "9am-5pm" });
    christchurch.staffList.push_back({ "Borris Johnson", "Staff", "Monday To Wednesday" ,"9am-5pm" });
    christchurch.staffList.push_back({ "Donald Trump", "Staff", "Thursday To Sunday", "9am-5pm" });

    int choice;
    do {
        std::cout << "\nMain Menu:\n"
                  << "1. Manage Wellington\n"
                  << "2. Manage Auckland\n"
                  << "3. Manage Christchurch\n"
                  << "Exit\n"
                  << "Enter Choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: manageStore(wellington);
            break;
        case 2: manageStore(auckland);
            break;
        case 3: manageStore(christchurch);
            break;
        case 4: std::cout << "Exiting Program.\n";
            break;
        default: std::cout << "Invalid Choice. Please Try Again.\n";
        }
    } while (choice != 4);
    
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