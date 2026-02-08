#include <iostream>
using namespace std;
void print(int *array, int size)
{
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ,";
    }
    cout << "\b]\n";
}
int *method1(int *array, int size)
{
    int *result = new int[size];
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = 0; j <= i; j++)
        {
            sum += array[j];
        }
        result[i] = sum / (i + 1);
    }
    return result;
}
int *method2(int *array, int size)
{
    int *result = new int[size];
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
        result[i] = sum / (i + 1);
    }
    return result;
}

int main()
{
    int array[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print(method1(array, 10), 10);
    print(method2(array, 10), 10);
    return 0;
}