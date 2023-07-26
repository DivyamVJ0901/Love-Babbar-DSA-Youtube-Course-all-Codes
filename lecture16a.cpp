// CODE FOR SELECTION SORT
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        int MinIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[MinIndex])
                MinIndex = j;
        }
        swap(arr[MinIndex], arr[i]);
    }
}

void selectionSort1(int arr[], int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        int MaxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[MaxIndex])
                MaxIndex = j;
        }
        swap(arr[MaxIndex], arr[i]);
    }
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int Divyam[8] = {23, 17, 89, 5, 63, 21, 43, 56};
    cout << "The given array is : ";
    PrintArray(Divyam, 8);
    cout << endl;
    selectionSort(Divyam, 8);
    cout << "The sorted array in increasing order is : ";
    PrintArray(Divyam, 8);
    cout << endl;
    selectionSort1(Divyam, 8);
    cout << "The sorted array in decreasing order is : ";
    PrintArray(Divyam, 8);
    return 0;
}