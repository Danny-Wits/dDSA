#include <iostream>
using namespace std;

int main()
{
    int *const ptr = NULL;
    int x = 10;
    ptr = &x;
    cout << *ptr;
    return 0;
}