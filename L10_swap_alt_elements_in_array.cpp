// Swapping alternate elements in an array
// For example
// If we have an Array like this
// arr[5] = {1,2,3,4,5,6}
// then our output should be
// arr[5] = {2,1,4,3,6,5}

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

void AlternateArray(int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

int main()
{
    int even[6] = {7, 15, 26, 87, 12, 3};
    int odd[7] = {7, 15, 26, 87, 12, 3, 45};

    PrintArray(even, 6);
    AlternateArray(even, 6);
    PrintArray(even, 6);

    cout << endl;

    PrintArray(odd, 7);
    AlternateArray(odd, 7);
    PrintArray(odd, 7);

    return 0;

}
