#include <iostream>
using namespace std;

class Product {
public:
    int id;
    string name;
    double price;

    Product(int P_id = 0, string P_name = "", double P_price = 0.0) {
        id = P_id;
        name = P_name;
        price = P_price;
    }
};

class ShoppingCart {
public:
    int productId;
    string productName;
    double productPrice;
    int quantity;

    ShoppingCart(int SC_Id = 0, string SC_Name = "", double SC_Price = 0.0, int qty = 1) {
        productId = SC_Id;
        productName = SC_Name;
        productPrice = SC_Price;
        quantity = qty;
    }
};

class Order {
private:
    Product products[5] = {
        Product(1, "Laptop", 800.00),
        Product(2, "Phone", 500.00),
        Product(3, "Tablet", 300.00),
        Product(4, "Headphones", 100.00),
        Product(5, "Charger", 20.00)
    };

    ShoppingCart cart[10];
    int cartCount = 0;

public:
    // view products so i can finally see
    void viewProducts() {
        cout << "Product ID    Name                 Price" << endl;
        for (int i = 0; i < 5; i++) {
            cout << products[i].id << "             ";
            cout << products[i].name;
          
            for (int j = products[i].name.length(); j < 20; j++) {
                cout << " ";
            }
            cout << products[i].price << endl;
        }
    }

    // Cart adding yippeee
    void addToCart() {
        int id;
        char choice;
        do {
            cout << "Enter the ID of the product you want to add to the shopping cart: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < 5; i++) {
                if (products[i].id == id) {
                    cart[cartCount] = ShoppingCart(products[i].id, products[i].name, products[i].price);
                    cartCount++;
                    cout << "Product added successfully!" << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Invalid product ID." << endl;
            }

            cout << "Do you want to add another product to the shopping cart? (Y/N): ";
            cin >> choice;
        } while (choice == 'Y' || choice == 'y');
    }

  
    void viewCart() {
        if (cartCount == 0) {
            cout << "Your shopping cart is empty." << endl;
            return;
        }

        cout << "Product ID    Name                 Price    Quantity" << endl;
        for (int i = 0; i < cartCount; i++) {
            cout << cart[i].productId << "             ";
            cout << cart[i].productName;
     
            for (int j = cart[i].productName.length(); j < 20; j++) {
                cout << " ";
            }
            cout << cart[i].productPrice << "      " << cart[i].quantity << endl;
        }

        char choice;
        cout << "Do you want to check out all the products? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            double total = 0;
            cout << "\nCheckout: " << endl;
            for (int i = 0; i < cartCount; i++) {
                total += cart[i].productPrice * cart[i].quantity;
                cout << cart[i].productName << " - " << cart[i].productPrice << " x " << cart[i].quantity << endl;
            }
            cout << "Total amount: " << total << endl;
            cout << "You have successfully checked out the products!" << endl;
            cartCount = 0; // car clearer
        }
    }


    void showMenu() {
        int choice;
        do {
            cout << "\nMenu" << endl;
            cout << "1 - View Products" << endl;
            cout << "2 - View Shopping Cart" << endl;
            cout << "3 - Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    viewProducts();
                    addToCart();
                    break;
                case 2:
                    viewCart();
                    break;
                case 3:
                    cout << "Exiting program..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 3);
    }
};

int main() {
    Order order;
    order.showMenu();
    return 0;
}
