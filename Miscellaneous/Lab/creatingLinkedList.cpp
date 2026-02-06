#include <iostream>
using namespace std;

struct Node
{
public:
    int data;
    Node *next = NULL;
    Node(int data) : data(data) {}
};
void print(Node *head) 
{
    cout << "[ ";
    while (head)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "\b\b\b  ]";
}
Node *head;
int createOrAddOnHead(int data)
{
    Node *newNode = new Node(data);
    if (!head)
        head = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

int main()
{
    char c;
    int n;
    while (true)
    {
        cout << "Do you want to continue 'y'/'n' : ";
        cin >> c;
        if (c != 'y')
            break;
        cout << "Enter the node you want to add :  ";
        cin >> n;
        createOrAddOnHead(n);
    }
    print(head);

    return 0;
}