#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Product {
    string name;
    int quantity;
    float price;
};

void addProduct(vector<Product>& inventory) {
    Product product;
    cout << "Enter product name: ";
    cin >> product.name;
    cout << "Enter product quantity: ";
    cin >> product.quantity;
    cout << "Enter product price: ";
    cin >> product.price;
    inventory.push_back(product);
    cout << "Product added successfully!" << endl;
}

void removeProduct(vector<Product>& inventory) {
    string name;
    cout << "Enter product name to remove: ";
    cin >> name;
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i].name == name) {
            inventory.erase(inventory.begin() + i);
            cout << "Product removed successfully!" << endl;
            return;
        }
    }
    cout << "Product not found!" << endl;
}

void showInventory(vector<Product>& inventory) {
    if (inventory.empty()) {
        cout << "Inventory is empty!" << endl;
        return;
    }
    cout << "Product\t\tQuantity\tPrice" << endl;
    for (int i = 0; i < inventory.size(); i++) {
        cout << inventory[i].name << "\t\t" << inventory[i].quantity << "\t\t" << inventory[i].price << endl;
    }
}

int main() {
    vector<Product> inventory;
    int choice;
    do {
        cout << "1. Add product" << endl;
        cout << "2. Remove product" << endl;
        cout << "3. Show inventory" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addProduct(inventory);
            break;
        case 2:
            removeProduct(inventory);
            break;
        case 3:
            showInventory(inventory);
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}