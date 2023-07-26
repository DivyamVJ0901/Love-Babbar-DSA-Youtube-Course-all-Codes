// MERGE SORT
#include <iostream>
using namespace std;

void Merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int size1 = mid - s + 1;
    int size2 = e - mid;

    int *first = new int[size1];
    int *second = new int[size2];
    
    int k = s;
    for (int i = 0; i < size1; i++)
        first[i] = arr[k++];

    k = mid + 1;
    for (int i = 0; i < size2; i++)
        second[i] = arr[k++];

    int i = 0, j = 0;
    k = s;
    while (i < size1 && j < size2)
    {
        if (first[i] < second[j])
            arr[k++] = first[i++];
        else
            arr[k++] = second[j++];
    }

    while (i < size1)
        arr[k++] = first[i++];

    while (j < size2)
        arr[k++] = second[j++];

    delete[] first;
    delete[] second;
}

void MergeSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    MergeSort(arr, s, mid);

    MergeSort(arr, mid + 1, e);

    Merge(arr, s, e);
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
    // int n;
    // cout << "Enter the size of element of array" << endl;
    // cin >> n;
    // int a[n] = {};
    // cout << "This code will give you sorted array " << endl;
    // cout << "Enter " << n << " random elements" << endl;
    // inputArray(a, n);
    // cout << "Your eneterd array is : ";
    // PrintArray(a, n);
    // MergeSort(a, 0, n - 1);
    // cout << "Your sorted array is : ";
    // PrintArray(a, n);
    // return 0;

    int arr[6] = {67, 43, 90, 23, 6, 189};
    cout << "Array is : ";
    PrintArray(arr, 6);
    MergeSort(arr, 0, 5);
    cout << "Sorted Array : ";
    PrintArray(arr, 6);
}
// Merge sort
// iska inversion count
// isko indexes ka use karke karna hai