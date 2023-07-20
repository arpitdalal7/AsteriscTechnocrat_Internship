#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Product {
    int productID;
    string name;
    int quantity;
    double price;
};


class InventoryManagementSystem {
private:
    vector<Product> inventory;

public:
    void addProduct() {
        Product newProduct;
        cout << "Enter product ID: ";
        cin >> newProduct.productID;
        cout << "Enter product name: ";
        cin.ignore();
        getline(cin, newProduct.name);
        cout << "Enter product quantity: ";
        cin >> newProduct.quantity;
        cout << "Enter product price: ";
        cin >> newProduct.price;

        inventory.push_back(newProduct);
        cout << "Product added successfully!\n";
    }

    void updateQuantity() {
        int productID, newQuantity;
        cout << "Enter product ID: ";
        cin >> productID;

        auto it = find_if(inventory.begin(), inventory.end(), [productID](const Product& product) {
            return product.productID == productID;
        });

        if (it != inventory.end()) {
            cout << "Enter new quantity: ";
            cin >> newQuantity;

            it->quantity = newQuantity;
            cout << "Quantity updated successfully!\n";
        } else {
            cout << "Product not found in the inventory.\n";
        }
    }

    void displayInventory() {
        cout << "Inventory:\n";
        cout << "Product ID\tProduct Name\tQuantity\tPrice\n";

        for (const auto& product : inventory) {
            cout << product.productID << "\t\t" << product.name << "\t\t" << product.quantity << "\t\t" << product.price << endl;
        }
    }

    void searchProduct() {
        int option;
        cout << "Search by:\n";
        cout << "1. Product ID\n";
        cout << "2. Product Name\n";
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 1) {
            int productID;
            cout << "Enter product ID: ";
            cin >> productID;

            auto it = find_if(inventory.begin(), inventory.end(), [productID](const Product& product) {
                return product.productID == productID;
            });

            if (it != inventory.end()) {
                cout << "Product ID: " << it->productID << endl;
                cout << "Product Name: " << it->name << endl;
                cout << "Quantity: " << it->quantity << endl;
                cout << "Price: " << it->price << endl;
            } else {
                cout << "Product not found in the inventory.\n";
            }
        } else if (option == 2) {
            string productName;
            cout << "Enter product name: ";
            cin.ignore();
            getline(cin, productName);

            auto it = find_if(inventory.begin(), inventory.end(), [productName](const Product& product) {
                return product.name == productName;
            });

            if (it != inventory.end()) {
                cout << "Product ID: " << it->productID << endl;
                cout << "Product Name: " << it->name << endl;
                cout << "Quantity: " << it->quantity << endl;
                cout << "Price: " << it->price << endl;
            } else {
                cout << "Product not found in the inventory.\n";
            }
        } else {
            cout << "Invalid option. Please try again.\n";
        }
    }
};

int main() {
    InventoryManagementSystem ims;
    int choice;

    do {
        cout << "Inventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Update Quantity\n";
        cout << "3. Display Inventory\n";
        cout << "4. Search Product\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ims.addProduct();
                break;
            case 2:
                ims.updateQuantity();
                break;
            case 3:
                ims.displayInventory();
                break;
            case 4:
                ims.searchProduct();
                break;
            case 5:
                cout << "Exiting Inventory Management System...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}
