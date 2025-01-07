#include <iostream>
using namespace std;

namespace a { // namespaces can store variables and functions
    int x = 2; // accesed by a::x
    int y;
}

namespace b {
    void printyay() { cout << "printyay" << endl; } // acceced by b::printyay

    // functions in namespaces are similar to static funtions in classes
}

namespace c{
    int d;
    int x;
}


using namespace c; // you can omit the use of the :: (scope resolution operator) by using the "using" keyword
// that kinda defeats the purpose of a namespace

int main() {
    cout << a::x << "\n";

    b::printyay();

    d = 2; // int d from namespace c

    cout << d;
}
