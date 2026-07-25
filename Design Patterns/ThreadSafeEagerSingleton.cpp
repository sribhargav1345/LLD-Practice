#include <iostream>
using namespace std;

class Singleton {
private:

    static Singleton* instance;

    Singleton() {
        cout<< "Singleton constructor called. New Object created." << endl;
    }

public:
    // static belongs to class, not objects.. static methods will be same for all objects
    static Singleton* getInstance() {
        return instance;
    }
};

Singleton* Singleton::instance = new Singleton();

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout<< (s1 == s2) <<endl;
}

/* The above has one of the main issue... Sometimes
the class may have expensive tasks, and not used anywhere
but here everytime, we are initializing the object.. with/without use.

So the above is called 'Eager Initialization'*/