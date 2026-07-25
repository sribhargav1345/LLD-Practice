#include <iostream>
#include <mutex>
using namespace std;

class Singleton {
private:

    static Singleton* instance;
    static mutex mtx;

    Singleton() {
        cout<< "Singleton constructor called. New Object created." << endl;
    }

public:
    // static belongs to class, not objects.. static methods will be same for all objects
    static Singleton* getInstance() {
        if(instance == nullptr) {
            lock_guard<mutex> lock(mtx);    // Lock for thread safety.
            if(instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout<< (s1 == s2) <<endl;
}

/* We have to avoid locking as much as possible. */
/* Putting it above the if check -> locks (instance !== nullptr) case also.. so we plan to put it inside if check*/
/* Putting lock_guard in instance == nullptr is wrong... since
    multiple threads may enter that if condition before locking.*/