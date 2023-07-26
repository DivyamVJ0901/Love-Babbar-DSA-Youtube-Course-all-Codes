#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front;
    int rear;

    Queue()
    {
        size = 10001;
        arr = new int[size];
        front = rear = 0;
    }

    void Push(int element)
    {
        if (rear == size)
            cout << "Overflow" << endl;
        else
        {
            arr[rear] = element;
            rear++;
        }
    }

    int Pop()
    {
        int last_element = arr[front];

        if (front == rear)
        {
            cout << "Underflow" << endl;
            return -1;
        }
        else
        {
            arr[front] = -1;
            front++;

            if (front == rear)
                front = rear = 0;
        }
        return last_element;
    }

    int front()
    {
        if (front == rear)
            return -1;
        return arr[front];
    }

    bool isEmpty()
    {
        if (front == rear)
            return true;
        return false;
    }
};

int main()
{

    return 0;
}