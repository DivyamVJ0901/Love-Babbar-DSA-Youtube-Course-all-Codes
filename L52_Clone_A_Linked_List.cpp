// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
// 	int val;
// 	Node* next;
// 	Node* arbit;
// 	Node(int x)
// 	{
// 		this->val = x;
// 		this->next = NULL;
// 		this->arbit = NULL;
// 	}
// };

// Node* cloneLinkedList(Node* head)
// {
// 	unordered_map<Node*, Node*> mp;
// 	Node *temp, *nhead;

// 	temp = head;
// 	nhead = new Node(temp->val);
// 	mp[temp] = nhead;

// 	while (temp->next != NULL) {
// 		nhead->next
// 			= new Node(temp->next->val);
// 		temp = temp->next;
// 		nhead = nhead->next;
// 		mp[temp] = nhead;
// 	}
// 	temp = head;

// 	while (temp != NULL) {
// 		mp[temp]->arbit = mp[temp->arbit];
// 		temp = temp->next;
// 	}

// 	return mp[head];
// }

// void printList(Node* head)
// {
// 	cout << head->val << "("
// 		<< head->arbit->val << ")";
// 	head = head->next;
// 	while (head != NULL) {
// 		cout << " -> " << head->val << "("
// 			<< head->arbit->val << ")";
// 		head = head->next;
// 	}
// 	cout << endl;
// }

// int main()
// {
// 	Node* head = new Node(1);
// 	head->next = new Node(2);
// 	head->next->next = new Node(3);
// 	head->next->next->next = new Node(4);
// 	head->next->next->next->next
// 		= new Node(5);
// 	head->arbit = head->next->next;
// 	head->next->arbit = head;
// 	head->next->next->arbit
// 		= head->next->next->next->next;
// 	head->next->next->next->arbit
// 		= head->next->next;
// 	head->next->next->next->next->arbit
// 		= head->next;
// 	cout << "The original linked list:\n";
// 	printList(head);
// 	Node* sol = cloneLinkedList(head);
// 	cout << "The cloned linked list:\n";
// 	printList(sol);

// 	return 0;
// }

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *arbitrary;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->arbitrary = NULL;
    }
};

void InsertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == NULL && tail == NULL)
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

Node *CloneLL(Node *&head)
{
    Node *CloneHead = NULL;
    Node *CloneTail = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        InsertAtTail(CloneHead, CloneTail, temp->data);
        temp = temp->next;
    }

    // Ab original LL ke beech me clone LL ko daalna hai
    Node *AsliNode = head;
    Node *NakliNode = CloneHead;

    while (AsliNode != NULL && NakliNode != NULL)
    {
        Node *faltu = AsliNode->next;
        AsliNode->next = NakliNode;
        NakliNode->next = faltu;

        faltu = NakliNode->next;
        NakliNode->next = AsliNode;
        AsliNode->next = faltu;
    }

    // Ab Random pointers bnane h clone Linked List ke liye
    while (temp != NULL)
    {
        if (temp->next != NULL)
            temp->next->arbitrary = temp->arbitrary ? temp->arbitrary : temp->arbitrary->next;
        temp = temp->next->next;
    }
    // Ab Revert krna hai second step ko ,, Jab humne Original LL ke beech me Clone LL ko insert kiya tha
    while (AsliNode != NULL && NakliNode != NULL)
    {
        AsliNode->next = NakliNode->next;
        AsliNode = AsliNode->next;

        NakliNode->next = AsliNode->next;
        NakliNode = NakliNode->next;
    }
    return CloneHead;
}

void PrintLL(Node *head)
{
    Node*temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
        if (temp == NULL)
            cout<<"NULL";
    }
    cout<<endl;   
}

int main()
{
    Node *node = new Node(56);

    Node*head = node;
    Node*tail = node;

    InsertAtTail(head , tail , 60);
    InsertAtTail(head , tail , 89);
    InsertAtTail(head , tail , 20);
    InsertAtTail(head , tail , 35);
    
    PrintLL(head);
    Node*sol = CloneLL(head);
    PrintLL(sol);

    return 0;
}

/*
Hum Ye cheez bhi use kr skte hai Random pointers bnane ke liye
if (temp->arbitrary != NULL)
    temp->next->arbitrary = temp->arbitrary->next;
else
    temp->next->arbitrary = temp->arbitrary;
*/