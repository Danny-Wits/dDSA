#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printVector(vector<string> list)
{
    for (string s : list)
    {
        cout << s << ",";
    }
    cout << endl;
}
void permutate(vector<string> list, int n, int r)

{
    if (n == r)
        printVector(list);
    else
    {
        for (int i = n; i <= r; i++)
        {
            swap(list[n], list[i]);
            permutate(list, n + 1, r);
            swap(list[n], list[i]);
        }
    }
}

int main()
{
    vector<string> v{"a", "b", "c"};
    permutate(v, 0, v.size() - 1);
    return 0;
}