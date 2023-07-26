#include <iostream>
#include <vector>
#include <string>
using namespace std;

string LowestCommonPref(vector<string> &arr, int n)
{
    n = arr.size();
    string ans = "";
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];
        bool match = true;
        for (int j = 1; j < arr.size(); j++)
        {
            if (arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
            break;
        else
            ans.push_back(ch);
    }
    return ans;
}

void PrintStr(string temp)
{
    for (int i = 0; i < temp.length(); i++)
        cout << temp[i];
    cout << endl;
}

int main()
{
    vector<string> ques = {"coding", "coders", "codingNinja", "codekaze"};
    string ans = LowestCommonPref(ques, 4);
    PrintStr(ans);
    return 0;
}