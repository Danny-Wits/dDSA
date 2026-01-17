#include <iostream>
using namespace std;

/**
 * Sorts the given array using selection sort algorithm.
 * @param array The array to sort.
 * @param size The size of the array.
 * @return The sorted array.
 */
int *selectionSort(int array[], int size)
{
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
void test(int arr[], int size)
{
    cout << "_____________________________________________\n\n";
    cout << "Sorting " << toString(arr, size) << endl;
    selectionSort(arr, size);
    cout << "Sorted array : " << toString(arr, size) << endl;
    cout << "\n_____________________________________________\n";
}
int main()
{
    int arr1[] = {4, 2, 7, 1, 3};
    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr3[] = {1, 2, 3, 4, 5};
    test(arr1, 5);
    test(arr2, 10);
    test(arr3, 5);
    return 0;
}