// FINDING FIRST AND LAST OCCURENCE OF AN ELEMENT IN AN ARRAY.
#include <iostream>
using namespace std;

int FirstOcc(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;

    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }

        else if (arr[mid] < key)
            s = mid + 1;

        else if (arr[mid] > key)
            e = mid - 1;

        mid = s + (e - s) / 2;
    }
    return ans;
}

int LastOcc(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;

    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }

        else if (arr[mid] < key)
            s = mid + 1;

        else if (arr[mid] > key)
            e = mid - 1;
            
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int even[13] = {1, 2, 3, 3, 3, 4, 8, 14, 45, 56};
    cout << "The first Occurence of 3 at index no. " << FirstOcc(even, 13, 3) << endl;
    cout << "The Last Occurence of 3 at index no. " << LastOcc(even, 13, 3) << endl;
    cout<<"The number of times 3 occurs in a code "<< (LastOcc(even, 13, 3) - FirstOcc(even, 13, 3) + 1)<<endl; 
    return 0;
}