// SORTING OF AN ARRAY

#include <iostream>
using namespace std;

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int step = 0;
void SortArray(int arr[], int n)
{
    int a = 0;
    int b = n - 1;

    while (a <= b)
    {
        if (arr[a] == 0)
        {
            a++;
        }

        if (arr[b] == 1)
        {
            b--;
        }

        while(a < b)
        {
            swap(arr[a], arr[b]);
        }
            a++;
            b--;
    }
}

int main()
{
    int arr[12] = {1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0};
    PrintArray(arr, 12);
    SortArray(arr, 12);
    PrintArray(arr, 12);

    cout << endl;

    // int arr[8] = {1, 1, 1, 0, 0, 0, 1, 0};
    // PrintArray(arr, 8);
    // SortArray(arr, 8);
    // PrintArray(arr ,  8);

    return 0;
}
