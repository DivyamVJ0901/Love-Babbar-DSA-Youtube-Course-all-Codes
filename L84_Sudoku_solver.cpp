#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &sudoku, int val)
{
    for (int i = 0; i < sudoku.size(); i++)
    {
        if (sudoku[row][i] == val)
            return false;
        if (sudoku[i][col] == val)
            return false;
        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }
    return true;
}

bool Solve(vector<vector<int>> &sudoku)
{
    int n = sudoku[0].size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (sudoku[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, sudoku, val))
                    {
                        sudoku[row][col] = val;
                        bool FurtherPossible = Solve(sudoku);
                        if (FurtherPossible)
                            return true;
                        else
                            sudoku[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void SudokuSolver(vector<vector<int>> &sudoku)
{
    Solve(sudoku);
}

void PrintMatrix(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> puzzle = {{3, 0, 6, 5, 7, 8, 0, 9, 2},
                                  {5, 2, 9, 1, 3, 4, 7, 6, 8},
                                  {4, 8, 0, 6, 2, 9, 5, 3, 1},
                                  {2, 6, 3, 4, 1, 5, 9, 8, 7},
                                  {9, 7, 4, 8, 6, 3, 1, 2, 5},
                                  {8, 5, 1, 7, 9, 2, 6, 4, 3},
                                  {1, 3, 8, 9, 4, 7, 2, 5, 6},
                                  {6, 9, 2, 3, 5, 0, 8, 7, 4},
                                  {7, 4, 5, 2, 8, 6, 3, 1, 9}};

    cout<<"The given puzzle is : "<<endl;
    PrintMatrix(puzzle);
    SudokuSolver(puzzle);
    cout<<endl;
    cout<<"The solved puzzle is : "<<endl;
    PrintMatrix(puzzle);
    return 0;
}
// 3 1 6 5 7 8 4 9 2
// 5 2 9 1 3 4 7 6 8
// 4 8 7 6 2 9 5 3 1
// 2 6 3 4 1 5 9 8 7
// 9 7 4 8 6 3 1 2 5
// 8 5 1 7 9 2 6 4 3
// 1 3 8 9 4 7 2 5 6
// 6 9 2 3 5 1 8 7 4
// 7 4 5 2 8 6 3 1 9