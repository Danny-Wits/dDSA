// Primitive Data Types
#include <iostream>
using namespace std;

int main()
{

    // Primitive Data Types
    cout << "Primitive Data Types" << endl;
    cout << "-------------------" << endl;
    cout << "int" << endl;
    cout << "float" << endl;
    cout << "double" << endl;
    cout << "char" << endl;
    cout << "bool" << endl;
    cout << "--------------" << endl;

    // Initialization
    cout << "Initialization" << endl;
    cout << "--------------" << endl;
    int i = 10;
    float f = 10.5;
    double d = 10.5;
    char c = 'A';
    bool b = true;
    cout << "i(int) = " << i << endl;
    cout << "f(float) = " << f << endl;
    cout << "d(double) = " << d << endl;
    cout << "c(char) = " << c << endl;
    cout << "b(bool)= " << b << endl;
    cout << "---------------" << endl;

    // Variants
    // works for numeric data types (int, float, double, char)
    cout << "Variants" << endl;
    cout << "--------" << endl;
    unsigned int ui = 10;
    long int li = 10;
    long long int lli = 10;
    cout << "ui (unsigned) = " << ui << " size:" << sizeof(ui) << endl;    // 4 bytes
    cout << "li (long)= " << li << " size:" << sizeof(li) << endl;         // 4 bytes
    cout << "lli (long long)= " << lli << " size:" << sizeof(lli) << endl; // 8 bytes
    return 0;
}