// CODE FOR PHONE KEYPAD PROBLEM
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(string &digit, string &output, int index, vector<string> &ans, string *map)
{
    if (index >= digit.length())
    {
        ans.push_back(output);
        return;
    }
    string value = map[digit[index] - '0'];
    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digit, output, index + 1, ans, map);
        output.pop_back(); // Backtracking
    }
}

vector<string> phone_keypad(string &digit)
{
    vector<string> ans;
    string output = "";
    if (digit.length() == 0)
        return ans;

    int index = 0;
    string map[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digit, output, index, ans, map);
    return ans;
}

void PrintString(vector<string> str)
{
    for (int i = 0; i < str.size(); i++)
        cout << str[i] << " ";
    cout << endl;
}

int main()
{
    string num = "47";
    vector<string> ans = phone_keypad(num);
    PrintString(ans);
    return 0;
}