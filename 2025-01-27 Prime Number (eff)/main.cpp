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
// how many primes do you think it got?
// leave your guess in the comments below!

int main() {
  unsigned long long int i = 0;
  unsigned long long int n = 0;

  // Open the file for writing
  ofstream outfile("primes.txt");

  // Check if the file opened successfully
  if (!outfile.is_open()) {
    cerr << "Error opening file!" << endl;
    return 1;
  }

  do {
    i++;
    if (isPrime(i)) {
      d.push_back(i);
      // Write to the file instead of the console
      outfile << n << ". \t\t\t" << i << "\n";
      n++;
    }
  } while (true);

  // Close the file
  outfile.close();

  return 0;
}
