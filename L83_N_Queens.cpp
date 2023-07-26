#include <iostream>
#include <vector>
using namespace std;

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board)
{
    vector<int> temp;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
            temp.push_back(board[i][j]);
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row, y = col;
    // Checking for same row
    while (y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
    }

    x = row, y = col;
    // Checking for diagonally upwards
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    x = row, y = col;
    // Checking for diagonally downwards
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x++;
        y--;
    }
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    // Base case
    if (col == n)
    {
        addSolution(ans, board);
        return;
    }

    // Solve 1 case and after recursion will handle it
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // is placing queen is safe
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            // Backtrack
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);

    return ans;
}

void Print(vector<vector<int>> temp)
{
    for (int i = 0; i <= temp.size(); i++)
    {
        for (int j = 0; j <= temp.size(); j++)
            cout << temp[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> arr = nQueens(4);
    Print(arr);
    return 0;
}