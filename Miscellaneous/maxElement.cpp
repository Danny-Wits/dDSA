#include <iostream>
#include <string>
using namespace std;

int max(int array[], int size)
{
    if (size == 0)
        return INT16_MIN;
    int max = array[1];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
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
void test(int array[], int size)
{
    cout << " ARRAY : " << toString(array, size) << " MAX : " << max(array, size) << endl;
}
int main()
{
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {-1, -2, -3, -4, -5};
    int array3[] = {1, 1, 1, 1, 1};
    int array4[] = {0, 0, 0, 0, 0};
    int array5[] = {5, 4, 3, 2, 1};
    test(array1, 5);
    test(array2, 5);
    test(array3, 5);
    test(array4, 5);
    test(array5, 5);
    return 0;
}