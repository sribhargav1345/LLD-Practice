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

class GarlicBread {
public:
    virtual void prepare() = 0;
    virtual ~GarlicBread() {};
};

class BasicGarlicBread: public GarlicBread {
public:
    void prepare() override {
        cout<< "Preparing basic garlic bread" << endl;
    };
};

class CheeseGarlicBread: public GarlicBread {
public:
    void prepare() override {
        cout<< "Preparing cheese garlic bread" << endl;
    };
};

class BasicWheatGarlicBread: public GarlicBread {
public:
    void prepare() override {
        cout<< "Preparing basic wheat garlic bread" << endl;
    };
};

class CheeseWheatGarlicBread: public GarlicBread {
public:
    void prepare() override {
        cout<< "Preparing cheese wheat garlic bread" << endl;
    };
};

class MealFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
    virtual GarlicBread* createGarlicBread(string& type) = 0;
};

class SinghBurger: public MealFactory {
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

    GarlicBread* createGarlicBread(string& type) override {
        if (type == "basic") {
            return new BasicGarlicBread();
        }
        else if (type == "cheese") {
            return new CheeseGarlicBread();
        }
        else {
            cout<<"Invalid GarlicBread type" << endl;
            return nullptr;
        }
    };
};

class KingBurger: public MealFactory {
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

    GarlicBread* createGarlicBread(string& type) override {
        if (type == "basic") {
            return new BasicWheatGarlicBread();
        }
        else if (type == "cheese") {
            return new CheeseWheatGarlicBread();
        }
        else {
            cout<<"Invalid wheat GarlicBread type" << endl;
            return nullptr;
        }
    };
};



int main() {
    string burgerType = "standard";
    string garlicBreadType = "cheese";

    MealFactory* mealfactory = new KingBurger();

    Burger* burger = mealfactory -> createBurger(burgerType);
    GarlicBread* garlicBread = mealfactory -> createGarlicBread(garlicBreadType);

    burger -> prepare();
    garlicBread -> prepare();

    return 0;
}