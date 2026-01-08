// Self-Referential Structures
#include <iostream>
using namespace std;

// These are structures that refer to themselfs using pointers
// Example a singly linked list
struct Node
{
    int data;
    Node *next;
};
void traverse(Node *head)
{
    while (head)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
int main()
{

    Node n2{20, NULL};
    Node n1{10, &n2};

    // Short hand for :
    //  n1.data = 10;
    //  n2.data = 20;
    //  n1.next = &n2;
    //  n2.next = NULL;

    traverse(&n1);

    // 10
    // 20

    return 0;
}