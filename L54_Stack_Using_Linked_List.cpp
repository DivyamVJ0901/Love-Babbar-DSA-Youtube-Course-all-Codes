#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *top;
    Node()
    {
        this->data = data;
        this->next = NULL;
        this->top = NULL;
    }
};

Node *top;

void push(int val)
{
    Node *temp = new Node();
    if (!temp)
    {
        cout << "Stack Overflow" << endl;
        return;
    }

    temp->data = val;
    temp->next = top;
    top = temp;
}

bool IsEmpty()
{
    if (top == NULL)
        return true;
    else
        return false;
}

int peek()
{
    if (IsEmpty)
        return top->data;
}

void pop()
{
    Node *temp;
    if (top == NULL)
    {
        cout << "Stack underflow" << endl;
        return;
    }
    else
    {
        temp = top;
        top = top->next;
        free(temp);
    }
}

void PrintStack()
{
    Node *temp;
    temp = top;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "NULL";
    }
    cout << endl;
}

int main()
{
    push(15);
    push(25);
    push(35);
    push(65);
    PrintStack();

    pop();
    pop();
    PrintStack();

    cout << "The peek element is : " << peek() << endl;

    if (IsEmpty)
        cout << "Not Empty" << endl;
    else
        cout << "Empty" << endl;
    return 0;
}
