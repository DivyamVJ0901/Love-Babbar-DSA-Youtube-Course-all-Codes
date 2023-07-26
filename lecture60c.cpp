#include <iostream>
using namespace std;

class CircularQueue
{
public:
    int *arr, front, rear, size;
    CircularQueue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
    }

    void enque(int element)
    {
        if (front == 0 && rear == size - 1 || rear == (front - 1) % (size - 1))
            cout << "Queue is overflow" << endl;

        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = element;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = element;
        }
        else
        {
            rear++;
            arr[rear] = element;
        }
    }

    void deque()
    {
        if (front == -1)
            cout<<"Queue is empty"<<endl;
        else if (front == rear)
        {
            front = -1;
            rear =-1;

        }
        else if (front = size-1)
            front = 0;
        else
            front++;
    }
};
int main()
{

    return 0;
}
