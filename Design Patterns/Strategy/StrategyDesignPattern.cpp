#include<iostream>
using namespace std;

// Strategy interface for walk
class WalkableRobot {
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};

class NormalWalk: public WalkableRobot {
public:
    void walk() override {
        cout<< "Walking normally" << endl;
    }
};

class NoWalk: public WalkableRobot {
public:
    void walk() override {
        cout<< "No walk here" << endl;
    }
};

// Strategy interface for Talk
class TalkableRobot {
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};

class NormalTalk: public TalkableRobot {
public:
    void talk() override {
        cout<< "Talking normally" << endl;
    }
};

class NoTalk: public TalkableRobot {
public:
    void talk() override {
        cout<< "No talk here" << endl;
    }
};

// For fly
class FlyableRobot {
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly: public FlyableRobot {
public:
    void fly() override {
        cout<< "Flying normally" << endl;
    }
};

class NoFly: public FlyableRobot {
public:
    void fly() override {
        cout<< "No fly here" << endl;
    }
};

class Robot {
protected:
    WalkableRobot* walkBehaviour;
    TalkableRobot* talkBehaviour;
    FlyableRobot* flybehaviour;

public:
    Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) {
        this -> walkBehaviour = w;
        this -> talkBehaviour = t;
        this -> flybehaviour = f;
    }

    void walk() {
        walkBehaviour -> walk();
    }

    void talk() {
        talkBehaviour -> talk();
    }

    void fly() {
        flybehaviour -> fly();
    }

    virtual void projection() = 0;
};

class CompanionRobot: public Robot {
public:
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f): Robot(w, t, f) {

    }

    void projection() override {
        cout<<"Companion Robot projection" << endl;
    }
};

int main() {
    Robot* r = new CompanionRobot(new NormalWalk(), new NoTalk(),new NormalFly());
    r -> walk();
    r -> talk();
    r -> fly();
    r -> projection();

    cout<<endl;
}