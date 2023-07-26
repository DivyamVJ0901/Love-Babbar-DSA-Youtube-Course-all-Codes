#include <bits/stdc++.h>
using namespace std;

vector<int> shopCandies(vector<int> candies, int N, int K)
{

    vector<int> ans;

    sort(candies.begin(), candies.end());

    // FOR MINIMUM AMOUNT OF MONEY
    int mini = 0, maxi = 0;
    int buyCandy = 0;
    int freeCandy = N - 1;

    while (buyCandy <= freeCandy)
    {
        mini += candies[buyCandy];
        buyCandy++;
        freeCandy -= K;
    }

    ans.push_back(mini);

    // FOR MAXIMUM AMOUNT OF MONEY
    buyCandy = N - 1;
    freeCandy = 0;
    while (buyCandy >= freeCandy)
    {
        maxi += candies[buyCandy];
        buyCandy--;
        freeCandy += K;
    }

    ans.push_back(maxi);

    return ans;
}

void Print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> ques = {3, 2, 1, 4};
    int N = 4, K = 2;
    vector<int> ans = shopCandies(ques, N, K);
    Print(ans);
    return 0;
}