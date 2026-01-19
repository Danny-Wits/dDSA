#include <iostream>
#include "../mychrono.h"
using namespace std;

int main()
{
    // adding to 1000
    long long sum = 0;
    myChrono::start();
    for (int i = 0; i < 100000; i++)
    {
        sum += i;
    }
    myChrono::end();

    auto duration = myChrono::nanoseconds();
    cout << "Sum : " << sum << " , Duration : " << duration << endl;

    // product to 1000
    long long product = 1;
    cout << sizeof(product) << endl;
    myChrono::start();
    for (int i = 1; i < 100000; i++)
    {
        product *= i;
    }
    myChrono::end();

    duration = myChrono::nanoseconds();
    cout << "Product : " << product << " , Duration : " << duration << endl;

    return 0;
}