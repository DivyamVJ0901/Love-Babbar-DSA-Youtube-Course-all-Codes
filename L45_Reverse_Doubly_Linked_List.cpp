#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHeadDLL(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTailDLL(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void Display(Node *&head, Node *&tail)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
        if (temp == NULL)
            cout << "NULL";
    }
    cout << endl;
}

void ReverseDoubLL(Node *head, Node *tail)
{
    
}

int main()
{

    Node *node1 = new Node(48);
    Node *head = node1;
    Node *tail = node1;

    insertAtHeadDLL(head, 5);
    insertAtHeadDLL(head, 6);
    insertAtTailDLL(tail, 99);
    insertAtTailDLL(tail, 56);
    Display(head, tail);
    return 0;
}