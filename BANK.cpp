#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Customer {
    string name;
    string address;
    string contact;
    
};

// Bank Account structure
struct BankAccount {
    int accountNumber;
    Customer customer;
    string accountType;
    double balance;
};

// Bank Management System class
class BankManagementSystem {
private:
    vector<Customer> customers;
    vector<BankAccount> accounts;
    int accountCounter;

public:
    BankManagementSystem() {
        accountCounter = 1;
    }

    void addCustomer() {
        Customer customer;
        cout << "Enter customer name: ";
        getline(cin >> ws, customer.name);
        cout << "Enter customer address: ";
        getline(cin >> ws, customer.address);
        cout << "Enter customer contact information: ";
        getline(cin >> ws, customer.contact);

        customers.push_back(customer);
        cout << "Customer added successfully!\n";
    }

    void createAccount() {
        BankAccount account;
        int customerID;
        cout << "Enter customer ID: ";
        cin >> customerID;

        
        auto it = find_if(customers.begin(), customers.end(), [customerID](const Customer& c) {
            return customerID == customerID;
        });

        if (it != customers.end()) {
            account.accountNumber = accountCounter++;
            account.customer = *it;
            cout << "Enter account type (e.g., savings, checking): ";
            cin >> account.accountType;
            account.balance = 0.0;

            accounts.push_back(account);
            cout << "Account created successfully!\n";
        } else {
            cout << "Customer not found!\n";
        }
    }

    void deposit() {
        int accountNumber;
        double amount;
        cout << "Enter account number: ";
        cin >> accountNumber;

        auto it = find_if(accounts.begin(), accounts.end(), [accountNumber](const BankAccount& acc) {
            return accountNumber == acc.accountNumber;
        });

        if (it != accounts.end()) {
            cout << "Enter amount to deposit: ";
            cin >> amount;

            it->balance += amount;
            cout << "Deposit successful! Current balance: " << it->balance << endl;
        } else {
            cout << "Account not found!\n";
        }
    }

    void withdraw() {
        int accountNumber;
        double amount;
        cout << "Enter account number: ";
        cin >> accountNumber;

        auto it = find_if(accounts.begin(), accounts.end(), [accountNumber](const BankAccount& acc) {
            return accountNumber == acc.accountNumber;
        });

        if (it != accounts.end()) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            if (amount <= it->balance) {
                it->balance -= amount;
                cout << "Withdrawal successful! Current balance: " << it->balance << endl;
            } else {
                cout << "Insufficient balance!\n";
            }
        } else {
            cout << "Account not found!\n";
        }
    }

    void displayAccounts() {
        cout << "Bank Accounts:\n";
        for (const auto& account : accounts) {
            cout << "Account Number: " << account.accountNumber << endl;
            cout << "Customer Name: " << account.customer.name << endl;
            cout << "Account Type: " << account.accountType << endl;
            cout << "Balance: " << account.balance << endl;
            cout << endl;
        }
    }
};

int main() {
    BankManagementSystem bms;
    int choice;

    do {
        cout << "Bank Management System\n";
        cout << "1. Add Customer\n";
        cout << "2. Create Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Display Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bms.addCustomer();
                break;
            case 2:
                bms.createAccount();
                break;
            case 3:
                bms.deposit();
                break;
            case 4:
                bms.withdraw();
                break;
            case 5:
                bms.displayAccounts();
                break;
            case 6:
                cout << "Exiting Bank System...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << endl;
    } while (choice != 6);

    return 0;
}
