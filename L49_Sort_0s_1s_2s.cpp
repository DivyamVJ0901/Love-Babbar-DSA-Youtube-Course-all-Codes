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

void PrintLL(Node *&head)
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

void sort0s1s2s(Node *&head)
{
    // if (head == NULL)
    //     return;

    Node *zeroStart = new Node(-1);
    Node *zerotail = zeroStart;

    Node *oneStart = new Node(-1);
    Node *onetail = oneStart;

    Node *twoStart = new Node(-1);
    Node *twotail = twoStart;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
            insertAtTail(zerotail, 0);
        else if (temp->data == 1)
            insertAtTail(onetail, 1);
        else if (temp->data == 2)
            insertAtTail(twotail, 2);

        temp = temp->next;
    }

    if (oneStart != NULL)
        zerotail->next = oneStart->next;
    else
        zerotail->next = twoStart->next;

    onetail->next = twoStart->next;
    twotail->next = NULL;

    head = zeroStart->next;

    delete zeroStart;
    delete oneStart;
    delete twoStart;
}

int main()
{
    Node *Vimdhayak_Ji = new Node(2);

    Node *head = Vimdhayak_Ji;
    Node *tail= Vimdhayak_Ji;

    insertAtHead(head , 1);
    insertAtHead(head , 2);
    insertAtHead(head , 1);
    insertAtHead(head , 0);
    PrintLL(head);

    sort0s1s2s(head);
    PrintLL(head);
    return 0;
}