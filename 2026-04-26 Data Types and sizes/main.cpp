#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    int x = 3;
    int* y = &x;
    int** z = &y;
    int* a = &&&z;

    return 0;
}