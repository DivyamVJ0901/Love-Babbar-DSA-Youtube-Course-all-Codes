// SEARCH IN A ROTATED AND SORTED ARRAY
#include <iostream>
using namespace std;

int Pivot(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int BinarySearch(int arr[], int n, int s, int e, int key)
{
    s = 0;
    e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }

        else if (arr[mid] > key)
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return -1;
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int findPosition(int arr[], int n, int k)
{
    int pivot = Pivot(arr, n);
    if (k >= arr[pivot] && k <= arr[n - 1])
    {
        return BinarySearch(arr, n, pivot, n - 1, k);
    }
    else
    {
        return BinarySearch(arr, n, 0, pivot - 1, k);
    }
}

int main()
{
    cout << "If your entered element is present in the array then you will get its index number" << endl;
    cout << "otherwise you will get -1." << endl;
    int k;
    cout << "Enter key element : " << endl;
    cin >> k;

    int Divyam[5] = {10, 6, 17, 43, 56};
    cout << "The given array is : ";
    PrintArray(Divyam, 5);
    cout << endl;

    cout << "The index of key element is : " << findPosition(Divyam, 5, k);
}
