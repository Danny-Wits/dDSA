#include <iostream>
#include "sortc.cpp"
using namespace std;
const bool debug = false;

void shellSort(int *a, int n)
{
    if (debug)
    {
        cout << "\nBefore sort : ";
        print(a, n);
    }
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int j = i;

            while (j >= gap && a[j] < a[j - gap])
            {
                swap(a[j - gap], a[j]);
                j -= gap;
            }
        }
    }

    if (debug)
    {
        cout << "After sort : ";
        print(a, n);
    }
}

int main()
{
    check(shellSort, 1000000);
    return 0;
}