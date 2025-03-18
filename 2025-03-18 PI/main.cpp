#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("output.txt");
    if (!outFile) {
        std::cerr << "Error opening file!\n";
        return 1;
    }

    int iterations = 1;  // Number of terms in the series
    double pi = 0.0;

    for (int k = 0; k < 1000000; ++k) {
        double term = 4.0 * ( (k % 2 == 0 ? 1.0 : -1.0) / (2.0 * k + 1.0) );
        pi += term;
        outFile << k << " " << pi << std::endl;  // Write iteration number and current value of π
    }

    outFile.close();
    std::cout << "Calculation complete. Check output.txt.\n";

    return 0;
}
