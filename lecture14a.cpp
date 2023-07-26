// PIVOT IN AN ARRAY
// The Pivot element is the only element for which the next element is smaller than it.

#include <iostream>
using namespace std;

int Pivot(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int main()
{
    int Divyam[6] = {1,7,3,6,5,6};
    cout << "The Pivot in given array is : " << Pivot(Divyam, 6) << endl;
    return 0;
}