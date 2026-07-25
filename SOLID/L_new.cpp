#include <bits/stdc++.h>
using namespace std;

class DepositOnlyAccount {
public:
    virtual void deposit(double amount) = 0;
};

class WithDrawlAccount: public DepositOnlyAccount {
public:
    virtual void withdraw(double amount) = 0;
};

class SavingAcc: public WithDrawlAccount {
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

class CurrentAcc: public WithDrawlAccount {
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

class FixedTermAcc: public DepositOnlyAccount {
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
};


class BankClient {
private:
    vector<WithDrawlAccount*> w_accounts;
    vector<DepositOnlyAccount*> d_accounts;

public:
    BankClient(vector<WithDrawlAccount*> w_accounts, vector<DepositOnlyAccount*> d_accounts){
        this -> w_accounts = w_accounts;
        this -> d_accounts = d_accounts;
    }

    void processTransactions() {
        for (WithDrawlAccount* acc: w_accounts) {
            acc -> deposit(1000);
            acc -> withdraw(500);
        }
        for (DepositOnlyAccount* acc: d_accounts) {
            acc -> deposit(1000);
        }
    }
};

int main() {
    vector<WithDrawlAccount*> w_accounts;
    vector<DepositOnlyAccount*> d_accounts;

    w_accounts.push_back(new SavingAcc());
    w_accounts.push_back(new CurrentAcc());

    d_accounts.push_back(new SavingAcc());
    d_accounts.push_back(new CurrentAcc());
    d_accounts.push_back(new FixedTermAcc());

    BankClient* client = new BankClient(w_accounts, d_accounts);
    client -> processTransactions();

}