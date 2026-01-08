// Basic Algorithms
#include <iostream>
using namespace std;

/*
Algorithm:

An algorithm is a finite sequence of well-defined instructions
that takes input, processes it, and produces output to solve a problem.

Traits:
- Input: zero or more inputs
- Output: at least one output
- Definiteness: steps are clear and unambiguous
- Finiteness: terminates in finite steps
- Effectiveness: each step is simple and executable
*/

// Example : Swapping two numbers , a simple algorithm using 3 steps

void swap(int &a, int &b) // input
{
    // finite : 3 steps
    // definite and effective : each step is simple and unambiguous

    int temp = a;
    a = b;
    b = temp;

    // ouput : swapped values
}

// FYI : more efficient ways to swap in place using bitwise XOR

void swapX(int &x, int &y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}
int main()
{

    int a = 10, b = 20;
    cout << "Before swapping: a = " << a << ", b = " << b << endl; // Before swapping: a = 10, b = 20
    swap(a, b);
    cout << "After swapping: a = " << a << ", b = " << b << endl; // After swapping: a = 20, b = 10

    int x = 10, y = 20;
    cout << "Before swapping: x = " << x << ", y = " << y << endl; // Before swapping: x = 10, y = 20
    swapX(x, y);
    cout << "After swapping: x = " << x << ", y = " << y << endl; // After swapping: x = 20, y = 10
    return 0;
}