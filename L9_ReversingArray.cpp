// REVERSE AN ARRAY

#include <iostream>
using namespace std;

void ReverseArray(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    cout << "The Reversed array is : ";
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void PrintArray(int arr[], int n)
{
    cout << "The actual array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[5] = {4, -9, 8, 7, -56};
    int arr2[6] = {15, 41, -78, 36, 12 , 54};
    cout<<endl;
    PrintArray(arr1, 5);
    ReverseArray(arr1, 5);
    cout << endl;
    PrintArray(arr2, 5);
    ReverseArray(arr2, 6);
    return 0;
}