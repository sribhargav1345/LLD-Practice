#include<bits/stdc++.h>
using namespace std;

class Character {
public:
    virtual string getAbilities() const = 0;
    virtual ~Character() {};
};

class Mario: public Character {
public:
    string getAbilities() const override {
        return "Mario";
    }
};

class CharacterDec: public Character {
protected:
    Character* character;
public:
    CharacterDec(Character* c) {
        this -> character = c;
    }
};

// Concrete Decorators
class HeightUp: public CharacterDec {
public:
    HeightUp(Character* c): CharacterDec(c) { }

    string getAbilities() const override {
        return character -> getAbilities() + "Height upping";
    }
};

class GunPowerUp: public CharacterDec {
public:
    GunPowerUp(Character* c): CharacterDec(c) { }

    string getAbilities() const override {
        return character -> getAbilities() + "Gunpower upping";
    }
};

class StarPowerUp: public CharacterDec {
public:
    StarPowerUp(Character* c): CharacterDec(c) { }

    string getAbilities() const override {
        return character -> getAbilities() + "Star power upping";
    }
};

int main() {
    Character* mario = new Mario();
    cout<< "Basic char: "<< mario -> getAbilities() <<endl;

    mario = new HeightUp(mario);
    cout<< "After HeightUP: " << mario -> getAbilities() << endl;

    mario = new GunPowerUp(mario);
    cout<< "After GunPowerUp: "<< mario -> getAbilities() << endl;

    mario = new StarPowerUp(mario);
    cout<< "After StarPowerUp: " << mario -> getAbilities() << endl;

    delete mario;

    return 0;
}