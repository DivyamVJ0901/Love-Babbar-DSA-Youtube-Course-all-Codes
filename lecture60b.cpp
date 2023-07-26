#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr, front, rear, size;
    Queue(int size)
    {
        this->size = size;
        front = 0;
        rear = 0;
    }

    void Push(int element)
    {
        if (rear == size)
            cout << "Queue overflow" << endl;

        else
        {
            arr[rear] = element;
            rear++;
        }
    }

    int Pop()
    {
        if (front == rear)
            cout << "Queue Underflow" << endl;
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front()
    {
        if (front == rear)
            return -1;

        else
            return arr[front];
    }

    bool isEmpty()
    {
        if (front == rear)
            return true;
        else
            return false;
    }
};

int main()
{

    return 0;
}