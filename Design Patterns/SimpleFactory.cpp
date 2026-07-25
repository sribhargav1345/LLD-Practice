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

class PremiumBurger: public Burger {
public:
    void prepare() override {
        cout<< "Expensive Burger"<< endl;
    }
};

class BurgerFactory {
public:
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicBurger();
        }
        else if(type == "standard"){
            return new StandardBurger();
        }
        else if(type == "premium") {
            return new PremiumBurger();
        }
        else {
            cout<<"Invalid burger type"<<endl;
            return nullptr;
        }
    }
};


int main() {
    string type = "basic";

    BurgerFactory* bf = new BurgerFactory();
    Burger* burger = bf -> createBurger(type);

    burger -> prepare();

    return 0;
}