#include<iostream>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
}

class ShoppingCart {
private:
    vector<Product*> products;

public:
    void addProduct(Product* p){
        products.push(p);
    }

    const vector<Product*>& getProducts() {
        return products;
    }

    // 1st responsibility
    double calculateTotal() {
        double total = 0;
        for (auto p: products) {
            total += (p -> price);
        }
        return total;
    }

    // 2nd responsibility
    void printInv() {
        cout<< "Printing Invoice Logic here"<< endl;
    }

    // 3rd responsibility
    void saveToDB() {
        cout<<"Save to DB logic here"<< endl;
    }
}