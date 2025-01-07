// Code for templates
// "class" and "typename" are interchangable.
// The

#include <iostream>
using namespace std;


template <class T> void bubbleSort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}

template <typename T, typename U>

int add(T a, U b) { // cannot have auto return type for template functions
    return a + b;
}



// Driver Code
int main()
{
    int a[5] = { 10, 50, 30, 40, 20 };
    int n = sizeof(a) / sizeof(a[0]);

    // calls template function
    bubbleSort<int>(a, n);

    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    


    cout << "Addition of 10 and 20: " << add(10, 20) << endl;

    return 0;
}