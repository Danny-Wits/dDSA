#include <iostream>
using namespace std;

int main()
{

    int x[] = {1, 2, 3, 4, 5};
    cout << 1 [x] << endl; // => *(1+x) == *(x+1) ==x[1]
    cout << 2 [x] << endl;
    cout << 3 [x] << endl;
    return 0;
}