// IMPLEMENTATION OF QUEUE USING LINKED LIST
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

class Queue
{
    Node *front;
    Node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    void Push(int element)
    {
        
    }
};
int main()
{

    return 0;
}