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
};

void insertionAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insertionAtEnd(Node *&tail, int val)
{
    Node *temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

void PrintLinkedList(Node *node)
{
    Node *temp = node;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
        if (temp == NULL)
            cout << "NULL";
    }
    cout << endl;
}

void insertionAtposition(Node *&tail, Node *&head, int position, int data)
{
    if (position == 1)
    {
        insertionAtHead(head, data);
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
        insertionAtEnd(tail, data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = node1->next;
    node1->next = newNode;
}

Node*FloydDetectionAlgoInLL(Node *&head)
{
    if (head == NULL)
        return NULL;

    Node *Torotoise = head;
    Node *Hare = head;

    while (Hare != NULL && Torotoise != NULL)
    {
        Hare = Hare->next;
        if (Hare->next != NULL)
            Hare = Hare->next;
        Torotoise = Torotoise->next;
        if (Torotoise == Hare)
        {
            cout<<"cycle at "<<Torotoise->data<<endl;
            return Torotoise;
        }
    }
    return NULL;
}

int main()
{
    Node *a = new Node(54);
    Node *head = a;
    Node *tail = a;

    insertionAtHead(head, 78);
    insertionAtHead(head, 12);

    insertionAtEnd(tail, 778);
    insertionAtEnd(tail, 963);

    PrintLinkedList(head);
    insertionAtposition(tail, head, 2, 100);

    tail->next = head->next;
    // PrintLinkedList(head);
    if (FloydDetectionAlgoInLL(head) != NULL)
        cout<<"yes , there is a loop"<<endl;
    else
        cout<<"No , there is no loop"<<endl;    
    return 0;
}