#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>
#include <iterator>
#include "../mychrono.h"
using namespace std;

#define mod %
using number = unsigned long long;

bool isPrime(number n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    number limit = sqrtl(n) + 1;
    for (number i = 2; i <= limit; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
number remainder(number num, number expo, number n)
{
    number result = 1;
    while (expo > 0)
    {
        while (expo % 2 == 0)
        {
            num = (num * num) mod n;
            expo /= 2;
        }
        expo -= 1;
        result = (result * num) mod n;
    }
    return result;
}
bool fermat_test(number n)
{
    if (n <= 1)
        return false;
    number q = n - 1;
    for (number i = 0; i < 5; i++)
    {
        number exp = q;
        number rem = 1;
        number a = rand() mod q + 1;

        // modded exponent
        if (remainder(a, exp, n) != 1)
            return false;
    }
    return true;
}

bool millar_rabin(number n)
{
    if (n <= 1)
        return false;
    number q = n - 1;
    number limit = log2l(n);
    for (number i = 0; i < limit; i++)
    {
        number exp = q;
        number rem = 1;
        number a = rand() % q + 1;
        number z = a;
        number y = 1;
        while (exp > 0)
        {
            while (exp % 2 == 0)
            {
                number x = z;
                z = (z * z) mod n;
                if (z == 1 && x != 1 && x != q)
                    return false;
                exp /= 2;
            }
            exp--;
            y = (y * z) mod n;
        }
        if (y != 1)
            return false;
    }
    return true;
}
void printVector(vector<number> v)
{
    cout << "[";
    for (number i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}
int main()
{
    srand(time(0));
    number limit = 100000000;
    vector<number> v1;
    vector<number> v2;
    vector<number> v3;
    myChrono::start();
    for (number i = 0; i < limit; i++)
    {
        if (isPrime(i))
            v1.push_back(i);
    }
    myChrono::end();
    cout << "\nTime taken for " << limit << " iterations is " << myChrono::milliseconds() << "ms\n";
    myChrono::start();
    for (number i = 0; i < limit; i++)
    {
        if (fermat_test(i))
            v2.push_back(i);
    }
    myChrono::end();
    cout << "\nTime taken for " << limit << " iterations is " << myChrono::milliseconds() << "ms\n";

    myChrono::start();
    for (number i = 0; i < limit; i++)
    {
        if (millar_rabin(i))
            v3.push_back(i);
    }
    myChrono::end();
    cout << "\nTime taken for " << limit << " iterations is " << myChrono::milliseconds() << "ms\n";
    cout << v1.size() << endl
         << v2.size() << endl
         << v3.size();

    return 0;
}

// Time taken for 100000000 iterations is 343499ms factor check

// Time taken for 100000000 iterations is 77236ms fermat_test

// Time taken for 100000000 iterations is 155747ms millar_rabin
// 5761455
// 5761606
// 5761504