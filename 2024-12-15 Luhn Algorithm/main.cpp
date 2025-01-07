#include <iostream>

using namespace std;

bool creditCardCheck(int cardNumber) {
    int sum = 0;
    int digit;
    int doubledDigit;
    int count = 0;

    // Convert card number to string for easier manipulation
    string cardNumberStr = to_string(cardNumber);

    // Reverse the card number for easier processing
    reverse(cardNumberStr.begin(), cardNumberStr.end());

    // Iterate through each digit in the reversed card number
    for (char c : cardNumberStr) {
        digit = c - '0';  // Convert character to integer

        // Double the value of every second digit
        if (count % 2 == 1) {
            doubledDigit = digit * 2;

            // If the doubled digit is greater than 9, subtract 9 from it
            if (doubledDigit > 9) {
                doubledDigit -= 9;
            }
        } else {
            doubledDigit = digit;
        }

        // Add the doubled digit to the sum
        sum += doubledDigit;

        // Increment the count
        count++;
    }

    // Check if the sum is divisible by 10
    return sum % 10 == 0;
}

int main() {
    int cardNumber;
    cout << "Enter a credit card number: ";
    cin >> cardNumber;

    if (creditCardCheck(cardNumber)) {
        cout << "Valid credit card number." << endl;
    } else {
        cout << "Invalid credit card number." << endl;
    }

    return 0;
}