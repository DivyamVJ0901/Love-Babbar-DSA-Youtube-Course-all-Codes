// IMPLEMENTATION OF DOUBLE LINKED LIST
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

void insertionAtPositionDLL(Node *&tail, Node *&head, int position, int data)
{
    if (position == 1)
    {
        insertAtHeadDLL(head, data);
        return;
    }

    Node *node1 = head;
    int count = 1;

    while (count < position - 1)
    {
        node1 = node1->next;
        count++;
    }

    if (node1->next == NULL)
    {
        insertAtTailDLL(tail, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = node1->next;
    node1->next->prev = newNode;
    node1->next = newNode;
    newNode->prev = node1;
}

void deletefromPositionDLL(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        Node *curr = head;
        Node *Prev = NULL;

        int count = 1;
        while (count < position)
        {
            Prev = curr;
            curr = curr->next;
            count++;
        }
        curr->prev = NULL;
        Prev->next = curr->next;
        if (curr->next)
            tail = Prev;
        curr->next = NULL;
        delete curr;
    }
}

void PrintLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    if (temp == NULL)
        cout << "NULL"<<endl;
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

    PrintLL(head);

    insertionAtPositionDLL(tail, head, 3, 20);
    PrintLL(head);

    // insertionAtPositionDLL(tail, head, 4, 520);
    // insertionAtPositionDLL(tail, head, 8, 450);

    deletefromPositionDLL(head, tail, 5);
    deletefromPositionDLL(head, tail, 1);
    PrintLL(head);

    // deletefromPositionDLL(head, tail, 6);
    // Display(head, tail);
    return 0;
}
