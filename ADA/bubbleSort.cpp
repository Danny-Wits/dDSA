#include <iostream>
using namespace std;
bool debug = false;
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
long long count = 0;
void bubbleSort(int *array, int n)
{
    if (n == 0)
        return;
    if (debug)
    {
        cout << "Before sort :";
        print(array, n);
    }
    for (int i = 0; i < n - 1; i++, count++)
    {
        for (int j = 0; j < n - 1 - i; j++, count++)
        {
            count++; // for if
            if (array[j] > array[j + 1])
            { // inplace swap
                array[j] = array[j] ^ array[j + 1];
                array[j + 1] = array[j] ^ array[j + 1];
                array[j] = array[j] ^ array[j + 1];
                count += 3; // for swap
            }
        }
    }
    if (debug)
    {
        cout << "After sort :";
        print(array, n);
    }
    cout << "n= " << n << " count = " << count << " rate : " << count / (n * n) << endl;
    count = 0;
}

void test(int n)
{
    int *x = new int[n];

    for (int i = n; i >= 1; i--)
    {
        x[n - i] = i;
    }
    bubbleSort(x, n);
}
int main()
{
    int problemSizeLimit = 1000;
    for (int i = 0; i < problemSizeLimit; i++)
    {
        test(i);
    }

    return 0;
}