#include <iostream>
using namespace std;

int expontiate(int number, int power)
{
    int result = 1;
    while (power > 0)
    {
        while (power % 2 == 0)
        {
            number *= number;
            power /= 2;
        }
        result *= number;
        power--;
    }
    return result;
}
int main()
{
    cout << expontiate(2, 10);
    return 0;
}