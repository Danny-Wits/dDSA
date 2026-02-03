#include <iostream>
using namespace std;

struct test
{
    char c;
    int i;
    double d;
};
struct test2
{
    char c1;
    int i1;
    char c2;
    double d;
    char c3;
    int i2;
};
struct test3
{
    double d;
    int i2;
    int i1;
    char c3;
    char c2;
    char c1;
};

int main()
{
    cout << sizeof(test) << endl;
    // 16 cuz
    // 1 char = 1 byte
    // 4 int = 4 bytes
    // 8 double = 8 bytes
    // total it should have been : 1+ 4 + 8 = 13 bytes

    // but to achieve symmetry it should be :
    // c _ _ _ i i i i //char is padded by 3 bits;
    // d d d d d d d d
    // total c + padding + i + d = 1 + 3 + 4 + 8 = 16

    // Some special cases where the order of declaration changes the padding

    cout << sizeof(test2) << endl; // 32
    cout << sizeof(test3) << endl; // 24

    return 0;
}