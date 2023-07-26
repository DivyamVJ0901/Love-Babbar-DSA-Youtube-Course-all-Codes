#include <iostream>
using namespace std;

class Heaps
{
public:
    int arr[100];
    int size;

    Heaps()
    {
        arr[0] = -1;
        size = 0;
    }

    void InsertInHeap(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void DeleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size]; // Pehli node ko last node par daal diya
        size--;             // Removal of last element

        // Further , Ham root node ko uski correct position pe laa rahe hai
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }

            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }

            else
                return;
        }
    }

    void Print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void Heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[largest] < arr[left])
        largest = left;

    if (right < n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        Heapify(arr, n, largest);
    }
}

void PrintArray(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    Heaps heap;

    heap.InsertInHeap(30);
    heap.InsertInHeap(20);
    heap.InsertInHeap(60);
    heap.InsertInHeap(40);
    heap.InsertInHeap(50);
    heap.Print();

    heap.DeleteFromHeap();
    heap.Print();

    int arr[6] = {-1, 30, 50, 60, 70, 20};
    int n = 5;
    cout << "The Initial heap is : ";
    PrintArray(arr, n);
    for (int i = n / 2; i >= 1; i--)
        Heapify(arr, n, i);

    cout << "The formed heap is : ";
    PrintArray(arr, n);
    return 0;
}