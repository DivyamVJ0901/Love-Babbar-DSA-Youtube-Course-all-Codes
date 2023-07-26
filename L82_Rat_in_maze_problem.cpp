#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n)
{
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && visited[newx][newy] != 1 && arr[newx][newy] == 1)
        return true;
    else
        return false;
}

void Solve(int x, int y, vector<vector<int>> &arr, int n,
           vector<string> &ans, vector<vector<bool>> &visited, string path)
{
    // Base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // 4 movements i.e, D L R U

    visited[x][y] = 1;

    // Down
    if (isSafe(x + 1, y, visited, arr, n))
        Solve(x + 1, y, arr, n, ans, visited, path + 'D');

    // Left
    if (isSafe(x, y - 1, visited, arr, n))
        Solve(x, y - 1, arr, n, ans, visited, path + 'L');

    // Right
    if (isSafe(x, y + 1, visited, arr, n))
        Solve(x, y + 1, arr, n, ans, visited, path + 'R');

    // Up
    if (isSafe(x - 1, y, visited, arr, n))
        Solve(x - 1, y, arr, n, ans, visited, path + 'U');

    visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> res;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";

    // edge case
    if (arr[0][0] == 0)
        return res;

    Solve(0, 0, arr, n, res, visited, path);
    return res;
}

void PrintStr(vector<string> temp)
{
    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = 0; j < temp[i].length(); j++)
        {
            cout << temp[j][i];
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> ques = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}};
    vector<string> ans = searchMaze(ques, ques.size());
    PrintStr(ans);
    return 0;
}