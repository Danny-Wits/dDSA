#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>

using namespace std;
class LinkedList;
class Node
{
    int data;
    Node *next = NULL;

public:
    Node(int element) : data(element) {}
    int getValue() { return data; }
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
        Node *temp;
        if (head == NULL)
        {
            head = new Node(element);
            tail = head;
            return;
        }
        temp = new Node(element);
        tail->next = temp;
        tail = temp;
    }

    void insert(int element, int index)
    {
        // For head insert || Empty list
        Node *temp;
        if (index <= 0 || head == NULL)
        {
            Node *newNode = new Node(element);
            newNode->next = head;
            head = newNode;
            if (tail == NULL)
                tail = newNode;
            return;
        }
        // getting to the prev pointer
        temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            if (temp->next == NULL)
                break;
            temp = temp->next;
        }
        // Inserting
        Node *newNode = new Node(element);
        newNode->next = temp->next;
        temp->next = newNode;

        // For end insert
        if (newNode->next == NULL)
            tail = newNode;
    }

    void remove(int element)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            Node *next = temp->next;
            if (temp->data == element)
            {
                if (prev)
                    prev->next = temp->next;
                else
                    head = temp->next;
                if (!next)
                    tail = prev;
                delete temp;
                temp = next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
    }
    void removeTail()
    {
        Node *temp = head;
        while (temp->next != tail && temp != NULL)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            Node *t = temp->next;
            temp->next = NULL;
            delete t;
        }
    }
    void removeHead()
    {
        if (!head)
            return;
        if (head->next)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            delete head;
            head = NULL;
        }
    }
    void reverse()
    {
        Node *prev = NULL;
        Node *cur = head;
        while (cur != NULL)
        {
            Node *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        tail = head;
        head = prev;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
    //! Quality of life :
    string toString()
    {
        string s = "[ ";
        Node *temp;
        temp = head;
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

#ifndef LINKED_LIST
// Test are AI generated:
int main()
{
    cout << "================ LINKED LIST TEST SUITE ================\n\n";

    LinkedList l;

    cout << "[TEST 1] Newly created list (should be empty)\n";
    cout << "List        : " << l << endl;

    cout << "[TEST 2] Adding elements 1, 2, 3, 4, 5\n";
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(4);
    l.add(5);
    cout << "List        : " << l << "\n\n";

    cout << "[TEST 3] Insert at head (value 0, index 0)\n";
    l.insert(0, 0);
    cout << "List        : " << l << "\n\n";

    cout << "[TEST 4] Insert in middle (value 99, index 3)\n";
    l.insert(99, 3);
    cout << "List        : " << l << "\n\n";

    cout << "[TEST 5] Insert at end (value 6, large index)\n";
    l.insert(6, 100);
    cout << "List        : " << l << "\n\n";

    cout << "[TEST 6] Remove head element (0)\n";
    l.remove(0);
    cout << "List        : " << l << "\n\n";

    cout << "[TEST 7] Remove middle element (99)\n";
    l.remove(99);
    cout << "List        : " << l << "\n\n";

    cout << "[TEST 8] Remove tail element (6)\n";
    l.remove(6);
    cout << "List        : " << l << "\n\n";

    cout << "[TEST 9] Remove multiple elements (remove 2, then 4)\n";
    l.remove(2);
    l.remove(4);
    cout << "List        : " << l << "\n\n";

    cout << "[TEST 10] Remove all remaining elements\n";
    l.remove(1);
    l.remove(3);
    l.remove(5);
    cout << "List        : " << l << endl;

    cout << "[TEST 11] Operations on empty list (remove / insert)\n";
    l.remove(10);    // no-op
    l.insert(42, 0); // insert into empty list
    cout << "List        : " << l << endl;
    l.remove(42);
    cout << "[TEST 12] Reverse list\n";
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(4);
    l.add(5);
    cout << "List before        : " << l << endl;
    l.reverse();
    cout << "List after         : " << l << endl;
    cout << "================ ALL TESTS COMPLETED ==================\n";
    return 0;
}

#endif