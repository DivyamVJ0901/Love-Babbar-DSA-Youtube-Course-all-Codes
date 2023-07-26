// CODE FOR SELECTION SORT USING RECURSION
#include <iostream>
using namespace std;

void SelectionSort(int arr[], int s, int e)
{
    if (s == e)
        return;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[s] > arr[i])
            swap(arr[s], arr[i]);
    }
    SelectionSort(arr, s + 1, e);
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
     int Vimdhayak_Ji[7] = {10,80,30,90,40,50,70};
        cout << "The unsorted array is : ";
        PrintArray(Vimdhayak_Ji, 7); 
        cout << "The SORTED array is : ";
        SelectionSort(Vimdhayak_Ji, 0, 6);
        PrintArray(Vimdhayak_Ji, 7);
    return 0;
}