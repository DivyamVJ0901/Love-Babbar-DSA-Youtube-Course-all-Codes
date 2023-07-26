#include <iostream>
#include <vector>
using namespace std;

void Solve(vector<int> digit, int index, vector<vector<int>> &ans)
{
    if (index >= digit.size())
    {
        ans.push_back(digit);
        return;
    }

    for (int i = index; i < digit.size(); i++)
    {
        swap(digit[index], digit[i]);
        Solve(digit, index + 1, ans);
        swap(digit[index], digit[i]);
    }
}

vector<vector<int>> Permutations(vector<int> &digit)
{
    vector<vector<int>> ans;
    int index = 0;
    Solve(digit, index, ans);
    return ans;
}

void Print2DArray(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    vector<int> divyam = {1, 2, 3};
    vector<vector<int>> ans = Permutations(divyam);
    Print2DArray(ans);
    return 0;
}