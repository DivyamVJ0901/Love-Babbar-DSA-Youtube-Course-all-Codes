#include<bits/stdc++.h>
using namespace std;

int longestAPwithCommonDiff(vector<int> &arr , int diff)
{
    unordered_map<int , int> dp;

    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i] - diff;
        int tempAns = 0;

        if(dp.count(temp))
            tempAns = dp[temp];

        dp[arr[i]] = 1 + tempAns;

        ans = max(ans , dp[arr[i]]);
    }
    return ans;
}

int main()
{
    vector<int> ques = {1,5,7,8,5,3,4,2,1};
    int commonDiff = -2;
    cout<<longestAPwithCommonDiff(ques , commonDiff);
    return 0;
}