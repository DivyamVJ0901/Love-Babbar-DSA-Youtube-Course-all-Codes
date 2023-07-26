#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->next = NULL;
        this->data = data;
    }
};

void InsertAtHead(Node *&head, int value)
{
    Node *temp = new Node(value);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int value)
{
    Node *temp = new Node(value);
    tail->next = temp;
    tail = temp;
}

Node *MergeTwoLinkedList(Node *&first, Node *&second)
{
    Node *curr1 = first;
    Node *curr2 = second;
    Node *next1 = curr1->next;
    Node *next2 = curr2->next;

    if (curr1 == NULL)
        return curr2;

    if (curr2 == NULL)
        return curr1;

    while (curr1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
            if (curr1->next == NULL && curr2->next == NULL)
            {
                curr1->next = curr2;
                return curr1;
            }
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return first;
}

void PrintLinkedList(Node *&head)
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

int main()
{
    Node *Divyam = new Node(50);
    Node *head1 = Divyam;
    Node *tail1 = Divyam;

    Node *Vijay = new Node(60);
    Node *head2 = Vijay;
    Node *tail2 = Vijay;

    InsertAtHead(head1, 30);
    InsertAtHead(head1, 10);
    PrintLinkedList(head1);
    InsertAtHead(head2, 40);
    InsertAtHead(head2, 20);
    PrintLinkedList(head2);

    Node*ans = MergeTwoLinkedList(head1 , head2);
    PrintLinkedList(ans);
    return 0;
}