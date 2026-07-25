#include<bits/stdc++.h>
using namespace std;


// Not completed.
class VendingMachine;

class NoCoinState;
class HasCoinState;
class DispenseState;
class SoldOutState;

class VendingState {
public:
    virtual VendingState* insertCoin(VendingMachine* machine, int coin) = 0;
    virtual VendingState* selectItem(VendingMachine* machine) = 0;
    virtual VendingState* dispense(VendingMachine* machine) = 0;
    virtual VendingState* returnCoin(VendingMachine* machine) = 0;
    virtual VendingState* refill(VendingMachine* machine, int quantity) = 0;
    virtual string getStateName() = 0;
};

class VendingMachine {
private:
    VendingState* currentState;
    int itemCount;
    int itemPrice;
    int insertedCoins;

    VendingState* noCoinState;
    VendingState* hasCoinState;
    VendingState* dispenseState;
    VendingState* soldOutState;

public:
    VendingMachine(int itemCount, int itemPrice);

    void insertCoin(int coin);
    void selectItem();
    void dispense();
    void returnCoin();
    void refill(int quantity);

    void printStatus();

    VendingState* getNoCoinState() {
        return noCoinState;
    }

    VendingState* getHasCoinState() {
        return hasCoinState;
    }

    VendingState* getDispenseState() {
        return dispenseState;
    }

    VendingState* getSoldOutState() {
        return soldOutState;
    }
};

class NoCoinState: public VendingState {
public:

};

// vendingmachine implementation
VendingMachine::VendingMachine(int itemCount,int price) {
    this -> itemCount = itemCount;
    this -> itemPrice = itemPrice;

    noCoinState = new NoCoinState();
    hasCoinState = new hasCoinState();
    dispenseState = new DispenseState();
    soldOutState = new SoldOutState();

    // Set initial state
    if (itemCount > 0){
        currentState = noCoinState;
    }
    else {
        currentState = soldOutState;
    }
};

void VendingMachine::insertCoin(int coin) {
    currentState = currentState -> insertCoin(this, coin);
}

void VendingMachine::selectItem() {
    currentState = currentState -> selectItem(this);
}

void VendingMachine::returnCoin() {
    currentState = currentState -> returnCoin(this);
}

void VendingMachine::dispense() {
    currentState = currentState -> dispense(this);
}

void VendingMachine::refill(int quantity) {
    currentState = currentState -> refill(this, quantity);
}

void VendingMachine::printStatus() {
    cout << "\n --- Vending Machine Status --- \n" ;
    cout<<"Items remaining: "<< itemCount << endl;
    cout<< "Inserted coin: " << insertedCoins << endl;
    cout<< "Current state: " << currentState -> getStateName() << endl;
}