#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // sets random seed
    int x = rand() % 101; // random number between 0 and 100

    if (x > 20 [[likely]]) {
        cout << "x is " << x << " and is greater than 20. This is likely." << endl;
    } else [[unlikely]] {
        cout << "x is " << x << " and is less than or equal to 20. This is unlikely." << endl;
    }

    return 0;
}
