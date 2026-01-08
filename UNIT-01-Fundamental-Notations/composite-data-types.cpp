// Composite Data Types
#include <iostream>
#include "../dprint.h"
using namespace std;

// 1. Struct : A User-defined data type , used to hold related data
//  used to store different data types in a single variable
struct Person
{
    string name;
    int age;
    float marks;
    void showDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Marks: " << marks << endl;
    }
} p1{"A", 10, 10.5}, p2{"B", 20, 20.5}; //  using brace Brace initialization

// 2. Unions : A user-defined data type in which all members share the same memory location.
// only one member is active at a time
// saves memory compared to struct
//  used in embedded systems, compilers and networking
union Data
{
    int i;
    float f;
    char c;
    void showDetails()
    {
        cout << "i = " << i << " , f = " << f << " , c = " << c << endl;
    }
} d;

// 3. Arrays : A collection of values of similar data types (contiguous memory locations)
//  used to store different data types in a single variable
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main()
{
    cout << "Structs :" << endl;
    p1.showDetails();
    p2.showDetails();
    cout << "---------------" << endl;
    //---------------
    // Structs :
    // Name: A
    // Age: 10
    // Marks: 10.5
    // Name: B
    // Age: 20
    // Marks: 20.5
    // ---------------
    cout << "Unions :" << endl;
    d.i = 1;
    d.showDetails();
    d.f = 2.5;
    d.showDetails();
    d.c = 'A';
    d.showDetails();
    cout << "---------------" << endl;
    // ---------------
    // Unions :
    // i = 1 , f = 1.4013e-045 , c =
    // i = 1075838976 , f = 2.5 , c =
    // i = 1075839041 , f = 2.50002 , c = A
    // only one member is active at a time , others a invalid / garbage
    // ---------------

    cout << "Arrays :" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " "; // accessing array using the subscript operator []
    }
    cout << endl;
    cout << "---------------" << endl;
    // ---------------
    // Arrays :
    // 1 2 3 4 5 6 7 8 9 10
    // ---------------

    return 0;
}