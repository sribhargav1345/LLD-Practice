#include<bits/stdc++.h>
using namespace std;

class Database {
public:
    virtual void save(string data) = 0;
};

class MySQLDatabase: public Database {
public:
    void save(string data) override {
        cout<< "Executing SQL Query " << data<< endl;
    }
};

class MongoDBDatabase: public Database {
public:
    void save(string data) override {
        cout<< "Executing MongoDB query " << data<< endl;
    }
};

// High level
class UserService {
private:
    Database* db;       // Dependency Injection

public:
    UserService(Database* database) {
        db = database;
    }

    void storeUser(string user) {
        db -> save(user);
    }
};

int main() {
    MySQLDatabase mysql;
    MongoDBDatabase mongodb;

    UserService service1(&mysql);
    service1.storeUser("Hi");

    UserService service2(&mongodb);
    service2.storeUser("Man");
}