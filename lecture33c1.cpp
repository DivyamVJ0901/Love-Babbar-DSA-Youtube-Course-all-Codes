// CODE FOR LINEAR SEARCH USING RECURSION
#include <iostream>
using namespace std;

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool LinearSearch(int arr[], int n, int key)
{
    cout << endl;
    cout << "Size of array is : " << n << endl;
    cout << "The array becomes : ";
    PrintArray(arr, n);
    cout << endl;
    // Base Condition
    if (n == 0)
        return 0;
    else if (arr[0] == key)
        return 1;
    else
        return LinearSearch(arr + 1, n - 1, key);
}

int main()
{
    int key;
    int Vimdhayak_Ji[5] = {2, 8, 9, 6, 4};
    cout << "Enter the key element " << endl;
    cin >> key;
    if (LinearSearch(Vimdhayak_Ji, 5, key))
        cout << "Element Found." << endl;
    else
        cout << "Element not found." << endl;
    return 0;
}