#include <string>
#include <iostream>
using namespace std;

/**
 * Searches for the given element in the array.
 * @param element The element to search for.
 * @param arr The array to search in.
 * @param size The size of the array.
 * @return The index of the element in the array, or -1 if not found.
 */
int search(int element, int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
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

void test(int element, int arr[], int size)
{
    cout << "_____________________________________________\n\n";
    cout << "Finding " << element << " in " << toString(arr, size) << endl;
    int index = search(element, arr, size);
    if (index == -1)
    {
        cout << "It was not found";
    }
    else
    {
        cout << "It was found at index : " << index + 1;
    }
    cout << "\n_____________________________________________\n";
}

int main()
{
    int arr[]{1, 2, 3, 4, 5, 6};

    test(0, arr, 4);
    test(2, arr, 4);
    test(68, arr, 4);
}