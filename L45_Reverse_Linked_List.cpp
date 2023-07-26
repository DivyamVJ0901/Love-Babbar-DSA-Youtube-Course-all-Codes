// REVERSE OF A LINKED LIST
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

void InsertionAtEnd(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void PrintLinkedList(Node *&node)
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

Node *ReverseLinkedList(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;
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

void ReverseLinkedListByRecursion(Node *&head, Node *&curr, Node *prev)
{
    curr = head;
    prev = NULL;

    if (curr == NULL)
    {
        head = prev;
        return;
    }

    return ReverseLinkedListByRecursion(head, curr->next, prev);
    curr->next = prev;
}

Node *ReverseLinkedListByRec(Node *&head)
{
    if (head == NULL || head->next)
    {
        return head;
    }

    Node *head2 = ReverseLinkedListByRec(head->next);

    head->next->next = head;
    head->next = NULL;

    return head2;
}

int main()
{
    Node *node = new Node(10);
    Node *head = node;
    Node *tail = node;

    InsertionAtHead(head, 14);
    InsertionAtEnd(tail, 54);

    PrintLinkedList(head);
    Node*ans = ReverseLinkedList(tail);
    PrintLinkedList(ans);
    return 0;
}