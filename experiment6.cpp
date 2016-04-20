#include <iostream>
#include <cmath>
using namespace std;
class B {
public:
    virtual void display() {
        cout << "Display() of Base Class B\n";
    }
};
class D1 : public B {
public:
    void display() {
        cout << "Display() of Derived Class D1\n";
    }        
};
class D2 : public B {
public:
    void display() {
        cout << "Display() of Derived Class D2\n";
    }
};
int main() {
    B *b;
    D1 d1;
    D2 d2;
    b = &d1;
    //This will call the display() of d1 since reference is of D1
    b -> display();
    b = &d2;
    //This will call the display() of d2 since reference is of D2
    b -> display();
    return 0;
}
