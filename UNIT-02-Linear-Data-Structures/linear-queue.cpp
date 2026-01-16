#include <iostream>
#define LINKED_LIST
#include "singly-linked-list.cpp"
using namespace std;

class Queue
{
    LinkedList list;

public:
    Queue() : list() {};

    void enqueue(int element)
    {
        list.add(element);
    }
    int dequeue()
    {
        int result = list.getTail().getValue();
        list.removeTail();
        return result;
    }
    bool isEmpty()
    {
        return list.isEmpty();
    }
};

int main()
{

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    while (!q.isEmpty())
    {
        cout << q.dequeue() << "\n";
    }
    cout << endl;

    return 0;
}