// CODE FOR SUM OF ARRAY ELEMENTS 
#include <iostream>
using namespace std;

int ArraySum(int arr[], int n)
{
    if (n == 0)
        return arr[0];
    else
        return arr[n - 1] + ArraySum(arr, n - 1);
}

int main()
{
    int Dogesh[4] = {1, 2, 4, 5};
    cout << ArraySum(Dogesh, 4);
    return 0;
}