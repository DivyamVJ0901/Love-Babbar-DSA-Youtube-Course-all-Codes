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

void InsertionAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void PrintLinkedList(Node *&node)
{
    Node *temp = node;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    if (temp == NULL)
        cout << "NULL";
    cout << endl;
}

Node *K_reverse(Node *head, int k)
{
    int count = 0;
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;
    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if (forward != NULL)
        head->next = K_reverse(forward, k);

    return prev;
}

int main()
{
    Node *Divyam = new Node(45);
    Node *head = Divyam;
    Node *tail = Divyam;

    int m = 10;
    for (int i = m; i <= 18; i += 2)
        InsertionAtHead(head, i);
    PrintLinkedList(head);

    Node *ans = K_reverse(head, 2);
    PrintLinkedList(ans);
    return 0;
}