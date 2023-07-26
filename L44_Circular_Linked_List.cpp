// IMPLEMENTATION OF CIRCULAR LINKED LIST
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void InsertAtPositionCLL(Node *&tail, int element, int data)
{
    // Empty List
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        temp->next = temp;
    }

    // Non empty list
    else
    {
        Node *curr = tail;

        while (curr->data != element)
            curr = curr->next;
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deletefromPositionCLL(Node *tail, int value)
{
    // Empty Linked List
    if (tail == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }

    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // for single node only
        if (tail == curr)
            tail = NULL;

        // for >= 2 nodes
        if (tail == curr)
            tail = prev;
        curr->next = NULL;
        delete curr;
    }
}

void Display(Node *&tail)
{
    Node *temp = tail;

    if (tail == NULL)
    {
        cout << "EMPTY LIST" << endl;
        return;
    }

    do
    {
        cout << tail->data << "->";
        tail = tail->next;
    } while (tail != temp);

    if (tail == temp)
        cout << "NULL";

    cout << endl;
}

bool checkCircular(Node *head)
{
    if (head == NULL)
        return 0;

    Node *temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;

    if (temp == NULL)
        return 0;

    return 1;
}

int main()
{
    Node *tail = NULL;

    InsertAtPositionCLL(tail, 3, 5);
    Display(tail);

    InsertAtPositionCLL(tail, 5, 7);
    Display(tail);

    InsertAtPositionCLL(tail, 7, 9);
    Display(tail);

    InsertAtPositionCLL(tail, 7, 78);
    Display(tail);

    if (checkCircular(tail))
        cout << "Yes, The LL is circular " << endl;
    else
        cout << "No, The LL is Not circular " << endl;

    deletefromPositionCLL(tail, 9);
    Display(tail);

    deletefromPositionCLL(tail, 78);
    Display(tail);

    deletefromPositionCLL(tail, 7);
    Display(tail);

    return 0;
}