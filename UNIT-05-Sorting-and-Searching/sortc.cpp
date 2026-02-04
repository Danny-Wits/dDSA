#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <string>
#include "../mychrono.h"
using namespace std;
void print(int *array, int n)
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ",";
    }
    cout << "\b]\n";
}
string toString(int array[], int size)
{
    string s = "[ ";
    for (int i = 0; i < size; i++)
    {
        s += (to_string(array[i]) + ", ");
    }
    s += "\b\b ]";
    return s;
}

bool areEqual(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}
int *randomArray(int size)
{
    int *array = new int[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % size + 1;
    }
    return array;
}
int *copy(int *array, int size)
{
    int *array2 = new int[size];
    for (int i = 0; i < size; i++)
    {
        array2[i] = array[i];
    }
    return array2;
}
bool check(void (*Xsort)(int *, int), int amount_of_test = 100, int size_limit = 100)
{
    srand(time(0));
    bool flag = true;
    long long totalTime = 0;
    for (int i = 0; i < amount_of_test; i++)
    {

        int size = rand() % (size_limit + 1);
        int *array1 = randomArray(size);
        int *array2 = copy(array1, size);
        myChrono::start();
        Xsort(array1, size);
        myChrono::end();
        totalTime += myChrono::milliseconds();
        sort(array2, array2 + size);
        flag &= areEqual(array1, array2, size);
        if (!flag)
            break;
    }
    if (flag)
        cout << "All tests Passed in " << totalTime << " milliseconds";
    else
        cout << "A Test Failed after " << totalTime << " milliseconds";
    return flag;
}