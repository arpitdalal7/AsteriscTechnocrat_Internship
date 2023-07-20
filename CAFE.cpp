#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


struct MenuItem {
    string name;
    double price;
};


class CafeBillingSystem {
private:
    vector<MenuItem> menu;
    vector<int> quantities;

public:
    CafeBillingSystem() {
        
        menu.push_back({"Samosa", 20.0});
        menu.push_back({"Dosa", 30.0});
        menu.push_back({"Tea", 10.0});
    }

    void displayMenu() {
        cout << "Menu:\n";
        for (size_t i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". " << menu[i].name << " - " << menu[i].price << "/-\n";
        }
    }

    void takeOrder() {
        int itemNumber, quantity;

        cout << "Enter item number (0 to finish): ";
        cin >> itemNumber;

        while (itemNumber != 0) {
            if (itemNumber < 1 || itemNumber > menu.size()) {
                cout << "Invalid item number. Please try again.\n";
            } else {
                cout << "Enter quantity: ";
                cin >> quantity;
                quantities.push_back(quantity);
            }

            cout << "Enter item number (0 to finish): ";
            cin >> itemNumber;
        }
    }

    void generateBill() {
        double totalAmount = 0.0;

        cout << "Order Details:\n";
        cout << setw(10) << left << "Item" << setw(10) << right << "Quantity" << setw(10) << right << "Price" << setw(10) << right << "Amount\n";
        cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

        for (size_t i = 0; i < menu.size(); i++) {
            if (quantities[i] > 0) {
                double amount = quantities[i] * menu[i].price;
                cout << setw(10) << left << menu[i].name << setw(10) << right << quantities[i] << setw(10) << right << menu[i].price << setw(10) << right << amount << endl;
                totalAmount += amount;
            }
        }

        cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
        cout << setw(30) << right << "Total Amount: " << setw(10) << right << totalAmount << endl;
    }
};

int main() {
    CafeBillingSystem cbs;
    int choice;

    do {
        cout << "Cafe Billing System\n";
        cout << "1. Display Menu\n";
        cout << "2. Take Order\n";
        cout << "3. Generate Bill\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cbs.displayMenu();
                break;
            case 2:
                cbs.takeOrder();
                break;
            case 3:
                cbs.generateBill();
                break;
            case 4:
                cout << "Exiting Cafe System...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}
