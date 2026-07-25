#include <iostream>
using namespace std;

class Burger {
public:
    virtual void prepare() {
        cout<<"Parent ni bro" << endl;
    };
    virtual ~Burger() {}
};

class BasicBurger: public Burger {
public:
    void prepare() override {
        cout<<"Preparing Basic Burger with bun,patty and ketchup" << endl;
    }
};

class StandardBurger: public Burger {
public:
    void prepare() override {
        cout<< "Preparing Standard Burger with bun,patty, cheese and lettuce" << endl;
    }
};

class BasicWheatBurger: public Burger {
public:
    void prepare() override {
        cout<< "Wheat Basic Burger"<< endl;
    }
};

class StandardWheatBurger: public Burger {
public:
    void prepare() override {
        cout<< "Wheat Standard Burger"<< endl;
    }
};

class BurgerFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
};

class SinghBurger: public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic"){
            return new BasicBurger();
        }
        else if(type == "standard") {
            return new StandardBurger();
        }
        else {
            cout<< "Invalid burger type" <<endl;
            return nullptr;
        }
    }
};

class KingBurger: public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic"){
            return new BasicWheatBurger();
        }
        else if(type == "standard") {
            return new StandardWheatBurger();
        }
        else {
            cout<< "Invalid burger type in king" <<endl;
            return nullptr;
        }
    }
};



int main() {
    string type = "standard";

    BurgerFactory* bf = new KingBurger();
    Burger* burger = bf -> createBurger(type);

    burger -> prepare();

    return 0;
}