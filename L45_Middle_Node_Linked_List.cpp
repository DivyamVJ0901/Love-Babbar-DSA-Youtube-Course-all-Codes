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

int getLength(Node *node)
{
    int len = 0;
    while (node != NULL)
    {
        len++;
        node = node->next;
    }
    return len;
}

Node *MidNode(Node *node)
{
    if (node == NULL || node->next == NULL)
        return node;

    if (node->next->next == NULL)
        return node->next;

    Node *slow = node;
    Node *fast = node->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

Node *MiddleNode(Node *head)
{
    int length = getLength(head);
    int ans = (length) / 2, count = 0;
    while (count < ans)
    {
        head = head->next;
        count++;
    }
    return head;
}

void PrintLL(Node *&node)
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

int main()
{
    Node *head = new Node(10);
    int num = 15;
    for (int i = 0; i < 6; i++)
        InsertionAtHead(head, num += 5);
    PrintLL(head);
    cout << "The length of LL is : " << getLength(head) << endl;
    Node *node1 = MiddleNode(head);
    PrintLL(node1);
    Node *node2 = MidNode(head);
    PrintLL(node2);
    return 0;
}