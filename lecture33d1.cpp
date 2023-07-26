// CODE FOR BINARY SEARCH USING RECURSION
#include <iostream>
using namespace std;

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Print(int arr[], int s, int e)
{
    for (int i = s; i <= e; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool BinarySearch(int arr[], int s, int e, int key)
{

    Print(arr, s, e);
    int mid = s + (e - s) / 2;
    cout << "The middle index is " << mid << " and array element is " << arr[mid] << endl
         << endl;

    // Element not found
    if (s > e)
        return false;

    // Element found
    else if (arr[mid] == key)
        return true;

    // Recursive call
    if (arr[mid] < key)
        return BinarySearch(arr, mid + 1, e, key);

    else if (arr[mid] > key)
        return BinarySearch(arr, s, mid - 1, key);
}

int main()
{
    int Dogesh[6] = {2, 4, 6, 10, 14, 18};

    if (BinarySearch(Dogesh, 0, 5, 16))
        cout << "Found" << endl;
    else
        cout << "Absent" << endl;
    return 0;
}

/*
Ye Saare questions recursion ka use krke karna hai-->>
// FINDING FIRST AND LAST OCCURENCE OF AN ELEMENT IN AN ARRAY.
// FINDING PEAK ELEMENT IN AN ARRAY
// PIVOT IN AN ARRAY
// SEARCH IN A ROTATED AND SORTED ARRAY
// FINDING SQUARE ROOT USING BINARY SEACH
*/