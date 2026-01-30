#include <iostream>
using namespace std;

class Node
{

public:
    int data = -1;
    Node *next = NULL;
};
// Global
Node *avail;
Node *head;
void add(int data)
{
    if (!avail)
    {
        cout << "No memory Available\n";
        return;
    }
    Node *newNode = avail;
    avail = avail->next;
    newNode->data = data;
    newNode->next = NULL;
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "added : " << newNode->data << "\n";
}
void print(Node *head)
{
    while (head)
    {
        cout << head->data << " -->";
        head = head->next;
    }
    cout << "\n";
}
int main()
{ // limit of memory
    int max = 10;

    avail = new Node;
    Node *temp = avail;

    for (int i = 0; i < max - 1; i++)
    {
        Node *freeNode = new Node;
        temp->next = freeNode;
        temp = temp->next;
    }
    print(avail);

    for (int i = 0; i < max + 1; i++)
    {
        add(i);
    }
    print(head);
    return 0;
}