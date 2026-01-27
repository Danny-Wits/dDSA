#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

class Disk
{
public:
    int value;
    Disk(int value) : value(value) {}
};

class Tower
{
public:
    vector<Disk> disks;

    void addDisk(Disk d)
    {
        if (topDiskValue() < d.value)
            throw runtime_error("Can't place larger disk on top");
        disks.push_back(d);
    }
    int topDiskValue()
    {
        if (disks.size() == 0)
            return INT32_MAX;
        return disks.at(disks.size() - 1).value;
    }
    Disk removeDisk()
    {
        Disk d = disks.at(disks.size() - 1);
        disks.pop_back();
        return d;
    }
    operator string()
    {
        int minLength = 40;
        string s = "|";
        for (Disk &d : disks)
        {
            s += to_string(d.value) + "--";
        }
        if (s.size() < minLength)
        {
            for (int i = s.size(); i < minLength; i++)
            {
                s += "-";
            }
        }
        s += ">";
        return s;
    }
};

void moveFromTo(Tower &t1, Tower &t2)
{
    t2.addDisk(t1.removeDisk());
}

Tower t1, t2, t3;
int moveCount = 0; // total moves
// Config:
int delay = 700; // time per move
int n = 5;       // number of disks
void print()
{
    moveCount++;
    system("cls");
    cout << "Start    " << (string)t1 << "\n\n"
         << "Target   " << (string)t2 << "\n\n"
         << "Auxalary " << (string)t3 << "\n\n"
         << "Move Count :" << moveCount;
    Sleep(delay);
}
void towerOfHanoi(int n, Tower &start, Tower &end, Tower &intermediate)
{
    if (n > 0)
    {
        towerOfHanoi(n - 1, start, intermediate, end); // move n-1 disks from start to intermediate
        moveFromTo(start, end);                        // move disk from start to end
        print();                                       // to print the state of the towers
        towerOfHanoi(n - 1, intermediate, end, start); // move n-1 disks from intermediate to end
    }
}

int main()
{
    for (int i = n; i > 0; i--)
    {
        Disk d(i);
        t1.addDisk(d);
    }
    towerOfHanoi(n, t1, t2, t3);
    return 0;
}