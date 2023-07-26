// CODE FOR INSERTION SORT
#include <iostream>
using namespace std;

void InsertionSort1(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = temp; 
    }
}

void InsertionSort2(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] < temp)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = temp;
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
    InsertionSort1(Divyam, 8);
    cout << "The sorted array in increasing order is : ";
    PrintArray(Divyam, 8);
    cout << endl;
    InsertionSort2(Divyam, 8);
    cout << "The sorted array in decreasing order is : ";

    PrintArray(Divyam, 8);
    return 0;
}