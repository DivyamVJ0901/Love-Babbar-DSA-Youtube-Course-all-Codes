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
    if (head != NULL)
        return 1;

    Node *temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;

    if (temp == NULL)
        return 0;
    else
        return 1;
}

int main()
{
    Node *Divyam = NULL;
    InsertAtPositionCLL(Divyam, 3, 5);

    InsertAtPositionCLL(Divyam, 5, 7);

    InsertAtPositionCLL(Divyam, 7, 9);

    InsertAtPositionCLL(Divyam, 9, 78);
    Display(Divyam);
    
    if (checkCircular(Divyam))
        cout<<"Yes, The LL is circular "<<endl;
    else
        cout<<"No, The LL is Not circular "<<endl;

    return 0;
}       
