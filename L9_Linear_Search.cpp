// LINEAR SEARCH
/*
Used to find a particular element in an array.
*/
#include <iostream>
using namespace std;

bool LinearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[5] = {45, 85, 78, 35, 19};
    cout << "Enter the value which you like to find out : " << endl;
    int element;
    cin >> element;
        
    bool found = LinearSearch(arr, 5, element);
    if (found)
    {
        cout << "Yes the entered element is present in the array." << endl;
    }
    else
    {
        cout << "No the entered element is absent in the array." << endl;
    }
    return 0;
}