#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const bool debug = true;
void print(int *array, int n)
{
    if (!debug)
        return;
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ",";
    }
    cout << "\b]\n";
}

void insertionSort(int *a, int n)
{
    cout << "\nBefore sort : ";
    print(a, n);
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

    cout << "After sort : ";
    print(a, n);
}

void test(int n)
{
    int *x = new int[n];
    srand(time(0));
    for (int i = n; i >= 1; i--)
    {
        x[n - i] = rand() % 100;
    }
    insertionSort(x, n);
}
int main()
{
    int problemSizeLimit = 10;
    for (int i = 0; i < problemSizeLimit; i++)
    {
        test(i);
    }

    return 0;
}