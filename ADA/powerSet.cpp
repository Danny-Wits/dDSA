#include <iostream>
#include <set>
#include <iterator>
using namespace std;
void printSet(set<int> s)
{
    cout << "[ ";
    for (int item : s)
    {
        cout << item << ",";
    }
    cout << "\b ],";
}
// todo : fix it

set<set<int>> s;
int powerSet(set<int> v)
{
    s.insert(v);
    for (int i = 0; i < v.size(); i++)
    {
        set<int> temp = v;
        temp.erase(next(temp.begin(), i));
        powerSet(temp);
    }
}

int main()
{
    set<int> v;
    v.insert(1);
    v.insert(2);
    v.insert(3);
    v.insert(4);
    v.insert(5);
    cout << "Vector : ";
    printSet(v);
    powerSet(v);
    cout << "\nNumber of subsets: " << s.size() << endl;
    cout << "Power set : [ ";
    for (auto i : s)
    {
        printSet(i);
    }
    cout << "]";

    return 0;
}