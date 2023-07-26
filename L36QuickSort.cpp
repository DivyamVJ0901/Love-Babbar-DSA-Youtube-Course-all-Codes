// QUICK SORT
#include <iostream>
using namespace std;

int Partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < arr[s])
            count++;
    }
    int PivotIndex = s + count;
    swap(arr[s], arr[PivotIndex]);

    int i = s, j = e;
    while (i < PivotIndex && j > PivotIndex)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        // if (i < PivotIndex && j > PivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return PivotIndex;
}

void QuickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int part = Partition(arr, s, e);
    QuickSort(arr, s, part - 1);
    QuickSort(arr, part + 1, e);
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void inputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int main()
{

    int a;
    cout << "Enter '1' for printing default stuff or '2' for inserting new array : " << endl;
    cin >> a;

    if (a == 1)
    {
        int Vimdhayak_Ji[7] = {10, 80, 30, 90, 40, 50, 70};
        cout << "The unsorted array is : ";
        PrintArray(Vimdhayak_Ji, 7);
        cout << "The SORTED array is : ";
        QuickSort(Vimdhayak_Ji, 0, 6);
        PrintArray(Vimdhayak_Ji, 7);
    }

    else if (a == 2)
    {
        int n;
        cout << "Enter the size of element of array" << endl;
        cin >> n;
        int arr[n] = {};
        cout << "Enter " << n << " random elements" << endl;
        inputArray(arr, n);
        cout << "Your eneterd array is : ";
        PrintArray(arr, n);
        QuickSort(arr, 0, n - 1);
        cout << "Your sorted array is : ";
        PrintArray(arr, n);
    }
    else
        cout << "Invalid Input !!!" << endl;
    return 0;
}