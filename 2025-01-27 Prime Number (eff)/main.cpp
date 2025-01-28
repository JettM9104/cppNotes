#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

bool isPrime(int x) {
  if (x < 2) {
    return false;
  }
  for (int i = 2; i < static_cast<int>(sqrt(x)) + 1; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}




vector<int> d = {};


int main() {
  unsigned long long int i = 0;
  unsigned long long int j = 0;
  unsigned long long int n = 0;
  unsigned long long int m = 0;

  ofstream outfile("primes.txt");

  if (!outfile.is_open()) {
    cerr << "Error opening file!" << endl;
    return 1;
  }

  do {
    i++;
    if (isPrime(i)) {
      d.push_back(i);

      outfile << n << "th iteration has value " << i << " (+" << i-j << ") with biggest increase " << m << "\n";
      n++;
      m = (i-j) > m ? i-j : m;

      j = i;
    }
  } while (true);

  outfile.close();

  return 0;
}
