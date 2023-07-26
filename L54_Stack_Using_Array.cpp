// IMPLEMENTAITION OF STACK USING ARRAY
#include <iostream>
using namespace std;

class Stack
{
    // Properties
public:
    int *arr, size, top;
    // Behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void PushOperation(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
            cout << "Stack Overflow" << endl;
    }

    void PopOpearation()
    {
        if (top >= 0)
            top--;
        else
            cout << "Stack Underflow" << endl;
    }

    int peakElement()
    {
        if (top >= 0)
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top >= 0)
            cout << "Stack is Not Empty" << endl;
        else
            cout << "Stack is Empty" << endl;
    }
};

int main()
{
    Stack s(5);
    s.PushOperation(8);
    s.PushOperation(23);
    s.PushOperation(45);
    s.PushOperation(71);
    cout << s.peakElement() << endl;
    s.PopOpearation();
    cout << s.peakElement() << endl;
    s.PopOpearation();
    cout << s.peakElement() << endl;
    s.PopOpearation();
    cout << s.peakElement() << endl;
    s.PopOpearation();
    cout << s.peakElement() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}
