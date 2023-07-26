// CODE TO GET ROW WISE SUM AND COLUMN WISE SUM IN A 2D ARRAY
#include <iostream>
#include <vector>
using namespace std;

int LargestRowSum(int arr[][3], int m, int n)
{
    int maxi = INT16_MIN;
    int rowNum = -1;
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum = sum + arr[i][j];
        cout << "The sum of " << i << " no. row is " << sum << endl;

        if (sum > maxi)
        {
            maxi = sum;
            rowNum = i;
        }
    }

    cout << "The maximum sum is : " << maxi << endl;
    cout << "The row with maximum sum is : ";
    return rowNum;
}
int LargestColSum(int arr[][3], int m, int n)
{
    int maxi = INT16_MIN;
    int ColNum = -1;
    int i, j, sum;
    for (int j = 0; j < n; j++)
    {
        sum = 0;
        for (i = 0; i < m; i++)
        {
            sum = sum + arr[i][j];
        }
        cout << "The sum of " << i << " no. column is " << sum << endl;
        if (sum > maxi)
        {
            maxi = sum;
            ColNum = j;
        }
    }

    cout << "The maximum sum is : " << maxi << endl;
    cout << "The column with maximum sum is : ";
    return ColNum;
}

int main()
{
    int arr[3][3] = {{1, 2, 4}, {3, 6, 9}, {4, 0, 8}};

    cout << "The matrix is : " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    int ans = LargestRowSum(arr, 3, 3);
    cout << ans;
    cout << endl;
    int ans1 = LargestColSum(arr, 3, 3);
    cout << ans1;
    return 0;
}
