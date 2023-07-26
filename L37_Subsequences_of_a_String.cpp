// CODE TO GET SUBSEQUENCES OF A STRING

#include <iostream>
#include <vector>
using namespace std;

void solve(string ques, string output, int index, vector<string> &ans)
{
    if (index >= ques.length())
    {
        ans.push_back(output);
        return;
    }

    solve(ques, output, index + 1, ans);
    output.push_back(ques[index]);
    solve(ques, output, index + 1, ans);
}

vector<string> SubSequences(string ques)
{
    vector<string> ans;
    string output;
    int index = 0;
    solve(ques, output, index, ans);
    return ans;
}

void Print(vector<string> s)
{
    for (int i = 0; i < s.size(); i++)
        cout<<s[i]<<endl;
}

int main()
{
    string s = "abc";
    vector<string> ans = SubSequences(s);
    Print(ans);
    return 0;
}