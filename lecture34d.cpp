// CODE FOR BUBBLE SORT USING RECURSION
#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    if (n == 0 || n == 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    BubbleSort(arr, n - 1);
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int Divyam[8] = {2, 3, 56, 1, 98, 16, 46, 32};
    cout << "The UNSORTED array is : " << endl;
    PrintArray(Divyam, 8);
    cout << "The SORTED array is : " << endl;
    PrintArray(Divyam, 8);
    BubbleSort(Divyam, 8);
    return 0;
}