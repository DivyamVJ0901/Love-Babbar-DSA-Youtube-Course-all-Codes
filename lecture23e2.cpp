// CODE FOR SEARCH AN ELEMENT IN A MATRIX USING BINARY SEARCH
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

void PrintMatrix(vector<vector<int>> mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> matrix;

    int num = 1;
    for (int i = 0; i < 3; i++)
    {
        vector<int> v1;
        for (int j = 0; j < 6; j++)
        {
            v1.push_back(num);
            num = num + 1;
        }
        matrix.push_back(v1);
    }


    cout << "The matrix is : " << endl;
    PrintMatrix(matrix);
    int key;
    cout << "Enter key : ";
    cin >> key;
    bool ans = SearchInMatrix(matrix, key);
    if (ans)
        cout << "Haan mil gya" << endl;
    else
        cout << "Nahi hai re baba" << endl;
    return 0;
}