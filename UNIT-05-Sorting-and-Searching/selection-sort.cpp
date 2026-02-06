#include <iostream>
#include "sortc.cpp"

using namespace std;
bool debug = true;
/**
 * Sorts the given array using selection sort algorithm.
 * @param array The array to sort.
 * @param size The size of the array.
 * @return The sorted array.
 */
void selectionSort(int array[], int size)
{
    if (debug)
    {
        cout << "Before sort :";
        print(array, size);
    }
    // Iterate through the array and find the minimum element
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        // Iterate through the subarray to find the minimum element
        for (int k = i; k < size; k++)
        {
            if (array[k] < array[min])
                min = k;
        }
        // Swap the minimum element with the current element
        swap(array[i], array[min]);
    }
    if (debug)
    {
        cout << "After sort :";
        print(array, size);
    }
}

int main()
{
    check(selectionSort);
    return 0;
}