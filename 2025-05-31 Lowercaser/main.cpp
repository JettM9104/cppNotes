#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream infile("text.txt");
    if (!infile) {
        cerr << "Error: Could not open input file 'text.txt'.\n";
        return 1;
    }

    ofstream outfile("text_lowercase.txt");
    if (!outfile) {
        cerr << "Error: Could not open output file 'text_lowercase.txt'.\n";
        return 1;
    }

    string word;
    while (infile >> word) {
        // Convert each character to lowercase
        transform(word.begin(), word.end(), word.begin(),
                  [](unsigned char c){ return tolower(c); });
        outfile << word << '\n';
    }

    cout << "Conversion complete. Lowercase words saved to 'text_lowercase.txt'.\n";
    return 0;
}
