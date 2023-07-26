// Given an array of integer numbers where 'arrr[i]' represents the num of pages in the 'ith' book.There are m numbers of students
// and the task is to allocate all the books to their students.Allocates books in such a way that :
// 1.) Each student gets at least one book.
// 2.) Each book should be allocated to a student.
// 3.) Bool allocation should be in a contiguos manner.

#include <iostream>
using namespace std;

bool IsPossible(int arr[], int n, int m, int mid)
{
    int StudentCount = 1;
    int PageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (PageSum + arr[i] <= mid)
        {
            PageSum = PageSum + arr[i];
        }
        else
        {
            StudentCount++;
            if (StudentCount > m || arr[i] > mid)
            {
                return false;
            }
            PageSum = arr[i];
        }
    }
    return true;
}

int BookAllocation(int arr[], int n, int m)
{
    int s = 0;
    int sum = 0;
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    int e = sum;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (IsPossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }

        else
        {
            s = mid + 1;
        }
        int mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int Divyam[4] = {10, 20, 30, 40};
    int book = BookAllocation(Divyam, 4, 2);
    cout << book;
    return 0;
}
