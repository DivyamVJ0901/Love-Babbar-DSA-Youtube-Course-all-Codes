#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> matrix;
    for (int i = 0; i < matrix[0].size(); i++)
    {
        vector<int> col;
        for (int j = 0; j < matrix.size(); j++)
            col.push_back(matrix[j][i]);

        sort(col.begin(), col.end());

        for (int j = 0; j < matrix.size(); j++)
            matrix[j][i] = col[j];
    }
    return 0;
}