#include <iostream>

int main() {
  std::array<int, 3> a = {2, 3, 2};

  std::cout << a.at(1); // Index starts at 0

  a.back(); // last vaule
  a.front(); // first value

  a.size(); // returns the size

  a.empty(); // returns wether if it is empty

  a.max_size(); // returns max size

  a.fill(3); // fills the array with 3s

  int& a1 = a[2];
  int& a2 = a[0];

  a1.swap(a2); // swaps a1 and a2


}