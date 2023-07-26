#include<iostream>
using namespace std;

int BinarySearch(int arr[], int n, int pivot , int key)
{
    int s = 0;
    int e = n - 1;

    int mid = (s + e) / 2;
    

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        if (key > arr[mid])
        {
            s = mid + 1;
        }

        if (key < arr[mid])
        {
            e = mid - 1;
        }

        mid = (s + e) / 2;
    }

    return -1;
}

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


int main(){


    
    return 0;
}

