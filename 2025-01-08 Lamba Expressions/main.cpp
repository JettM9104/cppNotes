#include <iostream>
using namespace std;

// lambda expressions can be declared inside a function and gets deleted outside the enclosing scope
// another advantage is you can use the auto keyword, acutally you have to use the auto keyword
// if you want to declare the type, after the parameter list () you can add  -> int, for example for the return type to be int.
// as seen below


int main() {
  auto add = [](int a, int b) -> int { // -> specifies return type, [] denots start of expressino, () is parameter list
    return a + b;
  };

  cout << add(20, 30); // use lambda expressinos
}