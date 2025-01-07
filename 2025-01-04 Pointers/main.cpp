#include <iostream>
#include <string>
using namespace std;

class eee {
public:
  int h;
  double d;
  string x;

  void method(int x) {
    h = x;
  }

private:
  int ph;
};
int main(int argc, char *argv[]) {
  int* ih = new int;


  eee* ds = new eee;

  ds->h = 3;
  ds->method(2);

  *ih = 32;

  cout << ds->h << "\n" << *ih; // should print 2 then 32

  delete ih;
}