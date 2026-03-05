#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;
#define mod %
bool isPrime(int n, int alpha = 10)
{
    int q = n - 1; // caching n-1 because we use it a lot
    int limit = alpha * log2(n);
    for (int i = 0; i < limit; i++)
    {
        // generate random number between  1 and n-1
        int a = rand() mod q + 1;
        int z = a;
        int m = q; // saving a and q is separate variables to avoid overwriting
        int result = 1;
        // Compute a power n-1 mod n
        while (m > 0)
        {
            while (m mod 2 == 0)
            {
                int x = z;
                z = (z * z) mod n;
                if (z == 1 and x != 1 and x != q)
                    return false;
                m = m / 2;
            }
            result = (result * z) mod n;
            m--;
        }
        // if remainder is not 1 ; composite
        if (result != 1)
            return false;
    }
    // else prime
    return true;
}

int main()
{
    srand(time(0));

    cout << isPrime(2) << endl;
    cout << isPrime(10) << endl;
    cout << isPrime(17) << endl;
    return 0;
}