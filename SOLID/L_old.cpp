#include <bits/stdc++.h>
using namespace std;

class Account {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAcc: public Account {
private:
    double balance;
public:
    SavingAcc () {
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        cout<< "Deposited"<< amount << "In Savings Acc" << endl;
    }

    void withdraw(double amount) {
        if(balance >= amount) {
            balance -= amount;
            cout<< "Withdraw" << amount << "In Savings Acc" << endl;
        }
        else {
            cout<< "Insufficient Balance" << endl;
        }
    }
};

class CurrentAcc: public Account {
private:
    double balance;
public:
    CurrentAcc () {
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        cout<< "Deposited"<< amount << "In Current Acc" << endl;
    }

    void withdraw(double amount) {
        if(balance >= amount) {
            balance -= amount;
            cout<< "Withdraw" << amount << "In Current Acc" << endl;
        }
        else {
            cout<< "Insufficient Balance" << endl;
        }
    }
};

class FixedTermAcc: public Account {
private:
    double balance;
public:
    FixedTermAcc () {
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        cout<< "Deposited"<< amount << "In Current Acc" << endl;
    }

    // Can't throw this type error to client
    void withdraw(double amount) {
        throw logic_error("Withdrawl not allowed");
    }
};


class BankClient {
private:
    vector<Account*> accounts;

public:
    BankClient(vector<Account*> accounts){
        this -> accounts = accounts;
    }

    void processTransactions() {
        for (Account* acc: accounts) {
            acc -> deposit(1000);

            try {
                acc -> withdraw(500);
            }
            catch(const logic_error& e) {
                cout<< "Exception: " << e.what() <<endl;
            }
        }
    }
};

int main() {
    vector<Account*> accounts;

    accounts.push_back(new SavingAcc());
    accounts.push_back(new CurrentAcc());
    accounts.push_back(new FixedTermAcc());

    BankClient* client = new BankClient(accounts);
    client -> processTransactions();

}