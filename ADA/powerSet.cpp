#include <iostream>
#include <vector>
using namespace std;
int count = 1;
void printVector(vector<int> list)
{
    if (list.size() == 0)
    {
        return;
    }
    ++::count;
    cout << "[";
    for (int s : list)
    {
        cout << s << ",";
    }
    cout << "\b],";
}
//todo : fix it 
int powerSet(vector<int> v)
{
    printVector(v);
    for (int i = 0; i < v.size(); i++)
    {
        vector<int> temp = v;
        temp.erase(temp.begin() + i);
        powerSet(temp);
    }
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << "Vector : ";
    printVector(v);
    cout << endl;
    powerSet(v);
    cout << "\nNumber of subsets: " << ::count - 1 << endl;
    return 0;
}