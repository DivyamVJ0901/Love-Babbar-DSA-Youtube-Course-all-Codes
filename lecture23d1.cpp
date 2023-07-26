// CODE FOR PRINTING WAVE COLUMNWISE
#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int j = 0; j < mCols; j++)
    {
        if (j % 2 != 0)
        {
            for (int i = nRows - 1; i >= 0; i--)
                ans.push_back(arr[i][j]);
        }
        else
        {
            for (int i = 0; i < nRows; i++)
                ans.push_back(arr[i][j]);
        }
    }
    return ans;
}

void PrintArray(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void Print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    cout << "The matrix is : " << endl;
    vector<vector<int>> Vimdhayak_Ji = {{1, 2, 4}, {2, 7, 9}, {3, 5, 4}};
    PrintArray(Vimdhayak_Ji);

    cout << "The matrix in wave (columnwise) is : " << endl;
    vector<int> ans = wavePrint(Vimdhayak_Ji, 3, 3);
    Print(ans);
    return 0;
}
