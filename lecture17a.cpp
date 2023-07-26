// CODE FOR BUBBLE SORT
#include <iostream>
using namespace std;

void BubbleSort1(int arr[], int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void BubbleSort2(int arr[], int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
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
    BubbleSort1(Divyam, 8);
    cout << "The sorted array in increasing order is : ";
    PrintArray(Divyam, 8);
    cout << endl;
    BubbleSort2(Divyam, 8);
    cout << "The sorted array in decreasing order is : ";
    PrintArray(Divyam, 8);

    return 0;
}