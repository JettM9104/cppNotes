#include <iostream>
#include <cmath>


using namespace std;

double upperbound = 0;    // Upper bound of the integration
double lowerbound = 360;    // Lower bound of the integration

int precision = 1'0000; // Number of subintervals for approximation

double finalint = 0;

int main() {
    for (int i = 0; i < precision; i++) {
        // Scale i to the range [lowerbound, upperbound]
        double x = lowerbound + (upperbound - lowerbound) * (static_cast<double>(i) / precision);

        // Approximate the integral value using the function f(x) = x^2
        //double value = pow(x, 2.0) * (upperbound - lowerbound) / precision;
        double value = sin(x * 2 * M_PI / 360) * (upperbound - lowerbound) / precision;
        finalint += value;

        // Print the intermediate sum and the current value
        printf("%f\t%f\n", finalint, value);
    }

    // Optionally, print the final result
    printf("Final sum: %f\n", finalint);

    return 0;
}
/*

#include <iostream>

double f(double x) {
  return 3*(x*x)+2*x+5;
}

float integralf(double lower_end, double high_end) {
  double a = lower_end;
  double b = high_end;
  double h = (b - a)/3;
  double area = 0.0;
  area = ((3*h)/8)*(f(a) + 3*f((2*a+b)/3) + 3*f((a+2*b)/3) + f(b));
  return area;
}

int main() {
  int lower = -3;
  int high = 5;
  std::cout << integralf(lower, high) << std::endl;

  return 0;
}
*/
