#include <iostream>
#include <unordered_map>
using namespace std;
int limit = 10;
int f(int n)
{
    if (n == 1 || n == limit)
        return 100;
    else
        return n;
}
void solver(int n)
{
    unordered_map<int, int> valMap;
    for (int i = 1; i <= n; i++)
    {
        int key = f(i);
        if (valMap.find(key) != valMap.end())
            cout << "a = " << valMap[key] << " b = " << i << " value = " << key;
        valMap[key] = i;
    }
}
int main()
{
    solver(limit);
    return 0;
}