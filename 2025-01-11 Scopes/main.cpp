#include <iostream>
using namespace std;

class class1 {
private:
  int pv;

protected:
  int pt;

public:
  int pu;

  static int s_pu;
};

class class2 : public class1 {
public:
  int x;
  void changept() {
    pt = 2;
  }
};

int main() {
  class2* d;

  d->changept();

}
