#include <bits/stdc++.h>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this -> name = name;
        this -> price = price;
    }
};

class ShoppingCart {
public:
    vector<Product*> products;

    void addProduct(Product* p){
        products.push_back(p);
    }

    const vector<Product*>& getProducts() {
        return products;
    }

    double calculateTotalPrice() {
        double total = 0;
        for (auto p:products) {
            total += (p -> price);
        }
        return total;
    }
};

class ShoppingCartPrinter {
private:
    ShoppingCart* cart;

public:
    ShoppingCartPrinter(ShoppingCart* cart) {
        this -> cart = cart;
    }

    void printInvoice() {
        cout<< "Printing Invoice function here"<< endl;
    }
};

class ShoppingCartStorage {
private:
    ShoppingCart* cart;

public:
    ShoppingCartStorage(ShoppingCart* cart) {
        this -> cart = cart;
    }

    void saveToDB() {
        cout<< "Save to DB function here"<< endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart -> addProduct(new Product("Laptop", 1500));
    cart -> addProduct(new Product("Mouse", 50));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer -> printInvoice();

    ShoppingCartStorage* storage = new ShoppingCartStorage(cart);
    storage-> saveToDB();

    return 0;
}