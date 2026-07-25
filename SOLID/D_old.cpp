#include<bits/stdc++.h>
using namespace std;

class MySQLDatabase {
public:
    void saveToSQL(string data) {
        cout<< "Executing SQL Query" << endl;
    }
};

class MongoDBDatabase {
public:
    void saveToMongo(string data) {
        cout<< "Executing MongoDB query" <<endl;
    }
};

class UserService {
private:
    MySQLDatabase sqlDb;
    MongoDBDatabase mongoDb;

public:
    void storeUserToSQL(string user) {
        sqlDb.saveToSQL(user);
    }

    void storeUserToMongo(string user) {
        mongoDb.saveToMongo(user);
    }
};

int main() {
    UserService service;
    service.storeUserToSQL("Hi");
    service.storeUserToMongo("Man");
}