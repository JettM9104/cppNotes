#include <iostream>
using namespace std;

//this code includes functions overloading and default arguments. also includes constexpr functions

// Also, tasks.json has code that allow the code to run in c++ 17 using ./main, c_cpp_properties.json is also added
// to enable c++17.

// code runner is set to c++17 in code-runner.executorMap, 

// "code-runner.executorMap": {
//     "cpp": "/usr/bin/g++ -std=c++17 -o $fileNameWithoutExt $fileName && $dir$fileNameWithoutExt",
//   
// }




/*
// 6/10

// Function with default arguments
void display(int a, int b = 0, int c = 0) {
    cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
}

int main() {
    display(10);         // Passes only one parameter
    display(10, 20);     // Passes two parameters
    display(10, 20, 30); // Passes three parameters
    return 0;
}

*/


/*
// 8/10
// Overloaded functions
void display(int a) {
    cout << "One parameter: a = " << a << endl;
}

void display(int a, int b) {
    cout << "Two parameters: a = " << a << ", b = " << b << endl;
}

void display(int a, int b, int c) {
    cout << "Three parameters: a = " << a << ", b = " << b << ", c = " << c << endl;
}

int main() {
    display(10);         // Calls the first function
    display(10, 20);     // Calls the second function
    display(10, 20, 30); // Calls the third function
    return 0;
}

*/



// Variadic template function
template <typename T, typename... Args>
void display(T first, Args... args) {
    cout << first << " ";
    if constexpr (sizeof...(args) > 0) {
        display(args...); // Recursive call
    } else {
        cout << endl;
    }
}

int main() {

    constexpr int arraysd = 10; // constexpr makes array size known at compile time.

    // instead of run time initialization, constexpr initializes variables, funtions, and others during compile time. 
    // do not use run time variables in constexpr functions. do not use dynamic memory allocation in constexpr functions.
    // do not use loops in constexpr functions.
    // do not use recursion in constexpr functions.
    // do not use exceptions in constexpr functions.
    // do not use any external libraries in constexpr functions.
    // do not use any standard library functions that are not constexpr in C++17.
    // do not use any variables that are not constexpr in C++17.
    // do not use any function that is not constexpr in C++17.
    // do not use any template specialization in C++17.
    // do not use any template instantiation in C++17.
    // do not use any template parameter that is not a type in C++17.
    // do not use any template parameter that is a reference in C++17.
    // do not use any template parameter that is a const reference in C++17.
    // do not use any template parameter that is a volatile reference in C++17.
    // constexpr varibles cannot be changed once initialized.
    // do not use any large, complex value or template instantiations in constexpr functions.

    


    int as[arraysd];


    display(10);                  // Single parameter
    display(10, 20);              // Two parameters
    display(10, 20, 30, 40, 50);  // Multiple parameters
    return 0;
}

