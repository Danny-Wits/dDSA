#include <iostream>
using namespace std;
int count = 1;
void printBoolArray(bool arr[], int size)
{
    cout << ::count << " [";
    for (int i = 0; i < size; i++)
    {
        cout << (arr[i] ? " true," : " false,");
    }
    cout << "\b ]\n";
    ::count++;
}
void helper(bool array[], int size, int i)
{
    if (i == size)
    {
        printBoolArray(array, size);
        return;
    }
    array[i] = false;
    helper(array, size, i + 1);
    array[i] = true;
    helper(array, size, i + 1);
}

void combinationGenerator(int n)
{
    bool *array = new bool[n];
    helper(array, n, 0);
    delete[] array;
}

int main()
{
    combinationGenerator(6);
    return 0;
}