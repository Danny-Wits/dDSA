#include <iostream>
#define ARRAY
#include "arrays.cpp"
using namespace std;

class Stack
{
    Array array;
    int cur;
    int size;

public:
    Stack(int size) : array(size), cur(0), size(size) {}
    void push(int element)
    {
        if (cur >= size)
        {
            cout << "Stack Overflow";
            return;
        }
        array[cur++] = element;
    }
    int peak()
    {
        if (isEmpty())
            return -1;
        return array[cur - 1];
    }
    int pop()
    {
        if (cur <= 0)
        {
            cout << "Stack Underflow";
            return -1;
        }
        return array[--cur];
    }
    bool isEmpty()
    {
        return cur == 0;
    }
};

#ifndef STACK
int main()
{
    Stack s(3);

    cout << "Pushing elements..." << endl;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Attempting overflow:" << endl;
    s.push(40); // Overflow

    cout << "\nTop element: " << s.peak() << endl;

    cout << "\nPopping elements..." << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << "\nAttempting underflow:" << endl;
    s.pop(); // Underflow

    return 0;
}
#endif