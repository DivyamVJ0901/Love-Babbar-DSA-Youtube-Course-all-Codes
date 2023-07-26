#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
    int size;
    int *arr;
    int front;
    int rear;

public:
    MyCircularQueue(int k)
    {
        size = 10001;
        arr = new int[size];
        front = rear = -1;
    }

    bool enQueue(int value)
    {
        if ((rear == size && front == 0) || (rear == (front - 1) % (size - 1)))
            return false;
        else if (front == -1)
            front = rear = 0;
        else if (rear == size - 1 && front != 0)
            rear = 0;
        else
            rear++;
        arr[front] = value;
        return true;
    }

    bool deQueue()
    {
        if (front == -1)
            return false;
        else if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
            front++;
        return true;
    }

    int Front()
    {
        if (front != -1)
            return arr[front];
        return -1;
    }

    int Rear()
    {
        if (rear != -1)
            return arr[rear];
        return -1;
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
            return true;
        return false;
    }
};

int main()
{

    return 0;
}