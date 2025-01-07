#include <iostream>
#include <string>
using namespace std;

class pizza {
private:
    int diameter;
    string topping1;
    string topping2;

protected: // passed onto derived class
    int derived = 0;

public:

    pizza() = default; // option to have no contrustucer

    pizza(int diameter) { // option to have diam only
        this->diameter = diameter;
    };
    pizza(int diameter, string topping1, string topping2) { // option to have all otps
        this->diameter = diameter;
        this->topping1 = topping1;
        this->topping2 = topping2;
    }

    int getDiameter() { return diameter; } // get topings
    string getTopping1() { return topping1; }
    string getTopping2() { return topping2; }

    void changeDiam(int x) { diameter = x; }

    static void fire() { cout << "oh no! the pizza is on fire"; } // static funtions can be accesed without an object by pizza::fire, similar to funtions in namepsaces.
    virtual void getStore() { cout << "found stroe"; } // virtual is a keyword to use if a derived class is to override it


};

class pizzaStore : public pizza {// pizzaStore is a derived class from class pizza. we use the public keyword because everything in public is private by default.
public:
    void getStore() override{} // derived class overrides functin getStore into nothing.
};

int main() {
    pizza PEET_ZAA;
}