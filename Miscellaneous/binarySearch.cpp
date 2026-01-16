#include <string>
#include <iostream>
using namespace std;

int binarySearch(int element, int array[], int size, int low, int high)
{
    if (high < low)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    // cout << "Low : " << low << "  High : " << high << " mid : " << mid << endl;
    // Right sub array
    if (array[mid] < element)
        return binarySearch(element, array, size, mid + 1, high);
    // Left sub array
    else if (array[mid] > element)
        return binarySearch(element, array, size, 0, mid - 1);
    return mid;
}

int binarySearchIterative(int element, int array[], int size)
{
    int low = 0, high = size - 1;
    while (high >= low)
    {
        int mid = (low + high) / 2;
        // Right sub array
        if (array[mid] < element)
            low = mid + 1;
        // Left sub array
        else if (array[mid] > element)
            high = mid - 1;
        else
            return mid;
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
    int index = binarySearch(element, arr, size, 0, size - 1);
    int index2 = binarySearchIterative(element, arr, size);
    cout << "Test : " << (index == index2 ? "SUCCESS" : "FAILED") << endl;
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
    int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    test(1, arr, 15);
    test(15, arr, 15);
    test(0, arr, 15);
    test(rand() % 20, arr, 15);
    test(rand() % 20, arr, 15);
    test(rand() % 20, arr, 15);
    test(rand() % 20, arr, 15);
    return 0;
}