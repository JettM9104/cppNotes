#include <iostream>
#include <string>
using namespace std;

string in1;
string in2;

char silly[2] = {'.', '.'};
char quiet = '.';

int offset = 0;

int main() {
    cin >> in1 >> in2;

    if (in1.length() == in2.length()) {
        for (int i = 0; i < in1.length(); i++) {
            if (in1[i] != in2[i]) {
                cout << in1[i] << " " << in2[1] << endl << "-";
                break;
            }
        }
    } else {
        for (int i = 0; i < in1.length(); i++) {
            if (in1[i + offset] != in2[i]) {
                if ((i + 1) < in1.length() && in1[i+1] == in2[i+1]) {
                    silly[0] = in1[i];
                    silly[1] = in2[i];
                } else {
                    offset++;

                    if (in1[i + offset] == in2[i]) {
                        quiet = in1[i+offset];
                    }
                }
            }
            if (silly[0] != '.' && silly[1] != '.' && quiet != '.') {
                break;
            }
        }
    }


    return 0;
}