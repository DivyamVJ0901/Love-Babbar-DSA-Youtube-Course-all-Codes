// FINDING PEAK ELEMENT IN AN ARRAY

#include <iostream>
using namespace std;

int PeakElement(int arr[], int n)
{
    int s = 0;
    int e = n - 1;

    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] < arr[mid + 1])
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
    int Divyam[8] = {4, 18, 12, 13, 8, 7, 0};
    cout << "The Peak element in given array is at index no. " << PeakElement(Divyam, 8);
    return 0;
}