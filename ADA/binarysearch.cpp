#include <iostream>
using namespace std;

int binarySearch(int item, int *array, int size)
{
    int high = size - 1;
    int low = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // can use mid= ( high+low )/2 but this is done to avoid int overflow
        // cuz low+high can overflow as it can be over the int limit
        if (item < array[mid])
            high = mid - 1;
        else if (item > array[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binarySearchRecursive(int item, int *array, int size, int low, int high)
{
    if (high < low)
        return -1;
    int mid = low + (high - low) / 2;
    if (item < array[mid])
        binarySearchRecursive(item, array, size, low, mid - 1);
    else if (item > array[mid])
        binarySearchRecursive(item, array, size, mid + 1, high);
    else
        return mid;
}

int main()
{
    int *array = new int[10]{0, 1, 2, 3, 4, 5, 6, 17, 18, 19};
    cout << "Element found at : " << binarySearch(2, array, 10) << endl;
    cout << "Element found at : " << binarySearch(1, array, 10) << endl;
    cout << "Element found at : " << binarySearch(8, array, 10) << endl;
    cout << "Element found at : " << binarySearch(19, array, 10) << endl;
    cout << "Element found at : " << binarySearch(17, array, 10) << endl;

    cout << "Element found at : " << binarySearchRecursive(2, array, 10, 0, 10) << endl;
    cout << "Element found at : " << binarySearchRecursive(1, array, 10, 0, 10) << endl;
    cout << "Element found at : " << binarySearchRecursive(8, array, 10, 0, 10) << endl;
    cout << "Element found at : " << binarySearchRecursive(19, array, 10, 0, 10) << endl;
    cout << "Element found at : " << binarySearchRecursive(17, array, 10, 0, 10) << endl;
    return 0;
}