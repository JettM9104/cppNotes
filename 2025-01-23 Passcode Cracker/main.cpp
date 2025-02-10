#include <iostream>
#include <ctime>
#include <string>

using namespace std;

bool attemptPassword(const string& attempt, const string& target) {
    return attempt == target;
}

unsigned long long int x = 0;

void bruteForcePassword(const string& target) {
    clock_t startTime = clock();

    const char startChar = 48; // ASCII 0
    const char endChar = 57; // ASCII 9

    string attempt = "";
    size_t currentLength = 1;

    while (true) {
        attempt.resize(currentLength, startChar);

        size_t maxIndex = pow(endChar - startChar + 1, currentLength);

        for (size_t index = 0; index < maxIndex; ++index) {
            // Generate current attempt
            for (size_t i = 0; i < currentLength; ++i) {
                attempt[i] = startChar + ((index / (int)pow(endChar - startChar + 1, i)) % (endChar - startChar + 1));

                cout << "Attempt: " << attempt << "\n";
                x++;
            }

            // Check if the attempt matches the password
            if (attemptPassword(attempt, target)) {
                clock_t endTime = clock();
                cout << "Password found: " << attempt << endl;
                cout << "Time taken: " << ((double)(endTime - startTime) / CLOCKS_PER_SEC) << " seconds" << endl;
                cout << "Total Attempts:" << x << endl;
                return;
            }
        }

        // Increment the password length
        ++currentLength;
    }
}

int main() {
    string targetPassword;

    cin >> targetPassword;

    
    cout << "Attempting to brute-force password: " << targetPassword << endl;

    bruteForcePassword(targetPassword);

    return 0;
}
