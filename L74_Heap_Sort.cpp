#include <iostream>
using namespace std;

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

void HeapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        // STEP - 1:
        swap(arr[size], arr[1]);
        // STEP - 2:
        Heapify(arr, size, 1);
        size--;
    }
}

int main()
{
    int arr[6] = {-1, 55, 60, 70, 50, 45};
    int n = 5;
    cout << "The Initial heap is : ";
    PrintArray(arr, n);

    for (int i = n / 2; i >= 1; i--)
        Heapify(arr, n, i);

    cout << "After heapify : ";
    PrintArray(arr, n);

    cout << "The sorted array is : ";
    HeapSort(arr, n);
    PrintArray(arr, n);

    return 0;
}