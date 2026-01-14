#define LINKED_LIST
#include "singly-linked-list.cpp"
class StackUnderFlowException : public runtime_error
{
public:
    StackUnderFlowException() : runtime_error("Stack underflow") {}
};
class Stack
{
    LinkedList list = LinkedList();

public:
    Stack() {}

    void push(int element)
    {
        list.insert(element, 0);
    }
    int peak()
    {
        return list.getHead().getValue();
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow";
            throw StackUnderFlowException();
        }
        int result = peak();
        list.removeHead();
        return result;
    }
    int isEmpty()
    {
        return list.isEmpty();
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);

    cout << "Stack: ";
    try
    {
        while (true)
        {
            cout << s.pop() << " ";
        }
    }
    catch (StackUnderFlowException e)
    {
    }

    return 0;
}