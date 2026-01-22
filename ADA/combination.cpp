#include <iostream>
using namespace std;

int combination(int n, int r)
{
    if (n < r)
        return 0;
    if (r == n || r == 0)
        return 1;
    return combination(n - 1, r) + combination(n - 1, r - 1);
}
int main()
{
    cout << "Test case 1: n = 5, r = 3 => " << combination(5, 3) << endl;
    cout << "Test case 2: n = 10, r = 4 => " << combination(10, 4) << endl;
    cout << "Test case 3: n = 20, r = 10 => " << combination(20, 10) << endl;
    return 0;
}