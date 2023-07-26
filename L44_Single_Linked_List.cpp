// IMPLEMENTATION OF SINGLE LINKED LIST
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
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertionAtposition(Node *&tail, Node *&head, int position, int data)
{
    if (position == 1)
    {
        insertAtHead(head, data);
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
        insertAtTail(tail, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = node1->next;
    node1->next = newNode;
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

void deletefromPosition(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
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
    Node *Divyam = new Node(15);
    Node *head = Divyam;
    Node *tail = Divyam;

    insertAtHead(head, 50);
    insertAtHead(head, 26);
    PrintLL(head);

    insertAtTail(tail, 65);
    insertAtTail(tail, 98);
    PrintLL(head);

    insertionAtposition(tail, head, 2, 80);
    PrintLL(head);

    deletefromPosition(head, 4);
    PrintLL(head);

    if (checkCircular(head))
        cout << "Yes, The LL is circular " << endl;
    else
        cout << "No, The LL is Not circular " << endl;
    return 0;
}