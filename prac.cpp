#include <bits/stdc++.h>
using namespace std;

void Print(int arr[3][3])
{
    cout << "The matrix is : " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int arr1[3][3] = {{1, 3, 5}, {2, 4, 6}, {7, 8, 9}};
    int arr2[3][3] = {{1, 2, 3}, {4, 8, 6}, {3, 1, 7}};

    Print(arr1);
    Print(arr2);

    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                sum += arr1[i][k] * arr2[k][j];
            }
        }
    }
    cout <<"The sum is : "<<sum << endl;
    return 0;
} 