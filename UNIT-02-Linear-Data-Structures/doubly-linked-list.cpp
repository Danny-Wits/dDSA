#include <iostream>
using namespace std;
class LinkedList;
class Node
{
    int data;
    Node *next = NULL;
    Node *prev = NULL;

public:
    Node(int element) : data(element) {}
    string toString()
    {
        return to_string(data);
    }
    friend LinkedList;
};

class LinkedList
{
    Node *head = NULL;
    Node *tail = NULL;
    Node EMPTY = Node(-1);

public:
    LinkedList() {}
    LinkedList(const LinkedList &) = delete;
    LinkedList &operator=(const LinkedList &) = delete;

    ~LinkedList()
    {
        Node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int element)
    {
        if (head == NULL)
        {
            head = new Node(element);
            tail = head;
            return;
        }
        Node *temp = new Node(element);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    void insert(int element, int index)
    {
        Node *temp = head;
        // For head insert || Empty list
        if (index <= 0 || head == NULL)
        {
            Node *newNode = new Node(element);
            newNode->next = head;
            if (head)
                head->prev = newNode;
            else
                tail = newNode;
            head = newNode;
            return;
        }

        for (int i = 0; i < index - 1; i++)
        {
            if (temp->next == NULL)
                break;
            temp = temp->next;
        }
        // Inserting
        Node *next = temp->next;
        Node *newNode = new Node(element);
        newNode->next = next;
        newNode->prev = temp;
        if (next)
        {
            next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        temp->next = newNode;
    }

    void remove(int element)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *next = temp->next;
            if (temp->data == element)
            {
                if (temp->prev)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;
                if (temp->next)
                    temp->next->prev = temp->prev;
                else
                    tail = temp->prev;
                delete temp;
                temp = next;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    void reverse()
    {
        Node *cur = head;
        while (cur != NULL)
        {
            Node *next = cur->next;
            cur->next = cur->prev;
            cur->prev = next;
            cur = next;
        }
        swap(head, tail);
    }
    //! Quality of life :
    string toString()
    {
        string s = "[ ";
        Node *temp = head;
        if (temp == NULL)
        {
            return "[ ]";
        }
        while (temp != NULL)
        {
            s += (temp->toString() + " -> ");
            temp = temp->next;
        }

        s = s.substr(0, s.size() - 4);
        s += " ] H: " + head->toString() + " T: " + tail->toString();
        return s;
    }
    void reverseTraversal()
    {
        Node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->toString() << " -> ";
            temp = temp->prev;
        }
    }
    Node getHead()
    {

        return (head == NULL ? EMPTY : *head);
    }
    Node getTail()
    {
        return (tail == NULL ? EMPTY : *tail);
    }
};
ostream &operator<<(ostream &out, LinkedList &list)
{
    return out << list.toString();
}
ostream &operator<<(ostream &out, Node node)
{
    return out << node.toString();
}

// Test are AI generated:
int main()
{
    cout << "================ DOUBLY LINKED LIST TEST SUITE ================\n\n";

    LinkedList l;

    // ------------------------------------------------------------
    cout << "[TEST 1] Empty list\n";
    cout << l << "\n\n";

    // ------------------------------------------------------------
    cout << "[TEST 2] Add elements 1, 2, 3, 4, 5\n";
    for (int i = 1; i <= 5; ++i)
        l.add(i);
    cout << l << "\n\n";

    // ------------------------------------------------------------
    cout << "[TEST 3] Insert at head (index 0): insert 100\n";
    l.insert(100, 0);
    cout << l << "\n\n";

    // ------------------------------------------------------------
    cout << "[TEST 4] Insert in middle (index 3): insert 200\n";
    l.insert(200, 3);
    cout << l << "\n\n";

    // ------------------------------------------------------------
    cout << "[TEST 5] Insert at tail (large index): insert 300\n";
    l.insert(300, 100);
    cout << l << "\n\n";

    // ------------------------------------------------------------
    cout << "[TEST 6] Remove head value (100)\n";
    l.remove(100);
    cout << l << "\n\n";

    // ------------------------------------------------------------
    cout << "[TEST 7] Remove middle value (200)\n";
    l.remove(200);
    cout << l << "\n\n";

    // ------------------------------------------------------------
    cout << "[TEST 8] Remove tail value (300)\n";
    l.remove(300);
    cout << l << "\n\n";

    // ------------------------------------------------------------
    cout << "[TEST 9] Remove multiple values (remove 3)\n";
    l.add(3);
    l.add(3);
    cout << "Before: " << l << endl;
    l.remove(3);
    cout << "After : " << l << "\n\n";

    // ------------------------------------------------------------
    cout << "[TEST 10] Reverse in place\n";
    l.reverse();
    cout << l << "\n\n";

    // ------------------------------------------------------------
    cout << "[TEST 11] Reverse traversal (tail -> head)\n";
    l.reverseTraversal();
    cout << "\n\n";

    // ------------------------------------------------------------
    cout << "[TEST 13] Clear list by removing all elements\n";
    l.remove(1);
    l.remove(2);
    l.remove(4);
    l.remove(5);
    cout << l << "\n\n";

    cout << "================ ALL TESTS COMPLETED ==================\n";
    return 0;
}
