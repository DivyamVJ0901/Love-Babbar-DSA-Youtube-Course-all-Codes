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

void InsertionAtHead(Node *&head, int element)
{
    Node *temp = new Node(element);
    temp->next = head;
    head = temp;
}

void InsertionAtTail(Node *&tail, Node *&head, int element)
{
    Node *temp = new Node(element);

    if (head == NULL || tail == NULL)
    {
        head = temp;
        tail = temp;
    }

    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *reverse(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node *AddLinkedList(Node *&node1, Node *&node2)
{
    int carry = 0;
    Node *santa = NULL;
    Node *banta = NULL;

    while (node1 != NULL || node2 != NULL || carry != 0)
    {
        int val1 = 0;
        int val2 = 0;

        if (node1 != NULL)
            val1 = node1->data;

        if (node2 != NULL)
            val2 = node2->data;

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        InsertionAtTail(santa, banta, digit);

        carry = sum / 10;

        if (node1 != NULL)
            node1 = node1->next;

        if (node2 != NULL)
            node2 = node2->next;
    }
    return santa;
}

void DisplayLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
        if (temp == NULL)
            cout << "NULL";
    }
    cout << endl;
}

int main()
{
    Node *Divyam = new Node(5);
    Node *Vijay = new Node(5);

    Node *head1 = Divyam;
    Node *tail1 = Divyam;
    Node *head2 = Vijay;
    Node *tail2 = Vijay;

    InsertionAtHead(head1, 4);
    InsertionAtHead(head2, 4);
    InsertionAtHead(head2, 3);

    // DisplayLL(head1);
    // DisplayLL(head2);

    head1 = reverse(head1);
    head2 = reverse(head2);

    DisplayLL(head1);
    DisplayLL(head2);

    Node *result = AddLinkedList(head1, head2);
    // DisplayLL(result);

    result = reverse(result);
    DisplayLL(result);

    return 0;
}


