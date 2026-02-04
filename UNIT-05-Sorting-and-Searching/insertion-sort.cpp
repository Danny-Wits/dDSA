#include <iostream>
#include "sortc.cpp"
using namespace std;
const bool debug = false;

void insertionSort(int *a, int n)
{
    if (debug)
    {
        cout << "\nBefore sort : ";
        print(a, n);
    }
    for (int i = 0; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    if (debug)
    {
        cout << "After sort : ";
        print(a, n);
    }
}

int main()
{
    check(insertionSort, 10000000, 1);

    return 0;
}