#include <iostream>
using namespace std;
struct Node
{

    int data;
    Node *next;
};

int main()
{
    Node n3{3, NULL};
    Node n2{2, &n3};
    Node n1{1, &n2};

    Node *temp = &n1;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}