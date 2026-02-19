#include <iostream>
using namespace std;

class Term
{
public:
    int coefficient;
    int exponent;
    Term *next;
    Term(int coefficient, int exponent, Term *next) : coefficient(coefficient), exponent(exponent), next(next) {};
};

void createNode(int coefficient) {}

void print(Term *head)
{
    while (head)
    {
        cout << head->coefficient << "x" << head->exponent << " + ";
        head = head->next;
    }
    cout << "\b\b  \n";
}

Term *add_polynomial(Term *head1, Term *head2)
{

    Term *p1 = head1;
    Term *p2 = head2;
    Term *result = new Term(0, 0, NULL);
    Term *p3 = result;

    while (p1 && p2)
    {
        if (p1->exponent > p2->exponent)
        {
            p3->next = p1;
            p3 = p3->next;
            p1 = p1->next;
        }
        else if (p2->exponent > p1->exponent)
        {
            p3->next = p2;
            p3 = p3->next;
            p2 = p2->next;
        }
        else
        {
            p1->coefficient += p2->coefficient;
            p3->next = p1;
            p1 = p1->next;
            p2 = p2->next;
            p3 = p3->next;
        }
    }
    if (p1)
    {
        p3->next = p1;
    }
    else
    {
        p3->next = p2;
    }
    return result->next;
}
int main()
{ // 7x2 + 2x - 3
    Term *f0 = new Term(-3, 0, NULL);
    Term *f1 = new Term(2, 1, f0);
    Term *f2 = new Term(7, 2, f1);
    // 3x + 2
    Term *s0 = new Term(2, 0, NULL);
    Term *s1 = new Term(3, 1, s0);

    print(f2);
    print(s1);

    print(add_polynomial(f2, s1));
    return 0;
}