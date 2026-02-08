#include <vector>
#include <random>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

mt19937 rng(time(0));
int random(int min = 0, int max = 100)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

void print(vector<int> v)
{
    for (auto e : v)
        cout << e << " ";
    cout << endl;
}
int method1 = 0;
int method2 = 0;
int findDup(vector<int> v)
{
    set<int> s;
    for (auto &&i : v)
    {
        if (s.find(i) != s.end())
        {
            method1 += s.size() + 1;
            cout << "Method 1 -> Steps : " << s.size() + 1;
            return i;
        }
        s.insert(i);
    }
}
int findDupRand(vector<int> v)
{
    int steps = 0;
    while (true)
    {
        steps++;
        int i = random(0, v.size() - 1);
        int j = random(0, v.size() - 1);
        if (i != j && v[i] == v[j])
        {
            method2 += steps + 1;
            cout << "Method 2 -> Steps : " << steps + 1;
            return v[i];
        }
    }
}

void test()
{
    vector<int> array;

    int size = random(10, 100);
    int r = random(1, size - 1);
    for (int i = 0; i < size / 2; i++)
    {
        if (i == r)
            continue;
        array.push_back(i);
    }
    for (int i = 0; i < size / 2; i++)
    {
        array.push_back(r);
    }

    shuffle(array.begin(), array.end(), rng);
    // this shuffles the array ..
    // if not shuffled method1 struggles
    // print(array);
    int x1 = findDup(array);
    cout << " Dup : " << x1 << endl;
    int x2 = findDupRand(array);
    cout << " Dup : " << x2 << endl;
}
int main()
{
    for (int i = 0; i < 2000; i++)
    {
        test();
    }
    cout << "total method 1 " << method1 << endl;
    cout << "total method 2 " << method2 << endl;
    return 0;
}