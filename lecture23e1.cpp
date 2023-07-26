#include <iostream>
#include <vector>
using namespace std;

bool SearchInMatrix(vector<vector<int>> &matrix, int key)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int s = 0;
    int e = row * col - 1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        int mid_element = matrix[mid / col][mid % col];

        if (mid_element == key)
            return 1;
        if (mid_element > key)
            e = mid - 1;
        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
    return 0;
}

int main()
{
    vector<vector<int>> matrix;

    int num = 10;
    for (int i = 0; i < 3; i++)
    {
        vector<int> v1;
        for (int j = 0; j < 3; j++)
        {
            v1.push_back(num);
            num = num + 2;                                                                          
        }
        matrix.push_back(v1);
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}