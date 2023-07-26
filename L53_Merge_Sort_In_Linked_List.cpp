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

void insertAtHead(Node *&head, int element)
{
    Node *temp = new Node(element);
    temp->next = head;
    head = temp;
}

Node *getMidNode(Node *&head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge2LL(Node *&node1, Node *&node2)
{
    if (node1 == NULL)
        return node2;

    if (node2 == NULL)
        return node1;

    Node *ans = new Node(-1);
    Node *temp = ans;

    while (node1 != NULL && node2 != NULL)
    {
        if (node1->data < node2->data)
        {
            temp->next = node1;
            temp = node1;
            node1 = node1->next;
        }
        else
        {
            temp->next = node2;
            temp = node2;
            node2 = node2->next;
        }
    }

    while (node1 != NULL)
    {
        temp->next = node1;
        temp = node1;
        node1 = node1->next;
    }

    while (node2 != NULL)
    {
        temp->next = node2;
        temp = node2;
        node2 = node2->next;
    }

    ans = ans->next;
    return ans;
}

Node *MergSortinLL(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;
    
    Node *midNode = getMidNode(head);

    Node *left = head;
    Node *right = midNode->next;

    midNode->next = NULL;

    left = MergSortinLL(left);
    right = MergSortinLL(right);

    Node *sol = merge2LL(left, right);

    return sol;
}

void PrintLL(Node *head)
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
    Node *Sambhar = new Node(89);
    Node *head = Sambhar;
    Node *tail = Sambhar;

    insertAtHead(head, 90);
    insertAtHead(head, 58);
    insertAtHead(head, 48);
    insertAtHead(head, 33);
    insertAtHead(head, 786);
    insertAtHead(head, 200);
    cout << endl
         << "The Given Linked List is : ";
    PrintLL(head);

    cout << "The Sorted Linked List is : ";
    MergSortinLL(head);
    PrintLL(head);
    cout << endl;
    return 0;
}