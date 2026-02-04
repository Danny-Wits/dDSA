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
    int gap = 1;
    while (gap < n / 3)
    {
        gap = 3 * gap + 1;
    }
    for (; gap > 0; gap /= 3)
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
    check(shellSort, 1000);
    return 0;
}