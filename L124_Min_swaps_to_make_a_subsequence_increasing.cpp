#include <bits/stdc++.h>
using namespace std;

int solveByRec(int index, vector<int> &nums1, vector<int> &nums2, bool swapped)
{
    int cnt = INT_MAX;
    if (index == nums1.size())
        return 0;

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];

    // important catch
    if (swapped)
        swap(prev1, prev2);

    // no swap
    if (nums1[index] > prev1 && nums2[index] > prev2)
        cnt = solveByRec(index + 1, nums1, nums2, 0);

    // swap
    if (nums1[index] > prev1 && nums2[index] > prev2)
        cnt = min(cnt, 1 + solveByRec(index + 1, nums1, nums2, 1));
    return cnt;
}
int solveByMemoization(int index, vector<int> &nums1, vector<int> &nums2, bool swapped, vector<vector<int>> &dp)
{
    int cnt = INT_MAX;
    if (index == nums1.size())
        return 0;

    if (dp[index][swapped] != -1)
        return dp[index][swapped];

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];

    // important catch
    if (swapped)
        swap(prev1, prev2);

    // no swap
    if (nums1[index] > prev1 && nums2[index] > prev2)
        cnt = solveByMemoization(index + 1, nums1, nums2, 0, dp);

    // swap
    if (nums1[index] > prev2 && nums2[index] > prev1)
        cnt = min(cnt, 1 + solveByMemoization(index + 1, nums1, nums2, 1, dp));

    dp[index][swapped] = cnt;
    return dp[index][swapped];
}

int solveByTabulation(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));

    for (int index = nums1.size() - 1; index >= 0; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int cnt = INT_MAX;
            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];

            if (swapped)
                swap(prev1, prev2);

            // no swap
            if (nums1[index] > prev1 && nums2[index] > prev2)
                cnt = dp[index + 1][0];

            // swap
            if (nums1[index] > prev2 && nums2[index] > prev1)
                cnt = min(cnt, 1 + dp[index + 1][1]);

            dp[index][swapped] = cnt;
        }
    }
    return dp[1][0];
}

int solveBySO(vector<int> &nums1, vector<int> &nums2)
{
    int swap = 0;
    int Noswap = 0;
    int currNoswap = 0;
    int currswap = 0;

    for (int index = nums1.size() - 1; index >= 0; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int cnt = INT_MAX;
            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];

            if (swapped)
            {
                int temp = prev1;
                prev1 = prev2;
                prev2 = temp;
            }

            // no swap
            if (nums1[index] > prev1 && nums2[index] > prev2)
                cnt = Noswap;

            // swap
            if (nums1[index] > prev2 && nums2[index] > prev1)
                cnt = min(cnt, 1 + swap);

            if (swapped)
                currswap = cnt;
            else
                currNoswap = cnt;
        }
        swap = currswap;
        Noswap = currNoswap;
    }
    return min(swap, Noswap);
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    // bool swapped = 0;
    // return solveByRec(1, temp1, temp2 , swapped);

    // vector<vector<int>> dp(nums1.size() + 1 , vector<int>(2 , -1));
    // return solveByMemoization(1 , nums1 , nums2 , swapped , dp);

    // return solveByTabulation(nums1 , nums2);

    return solveBySO(nums1, nums2);
}

int main()
{
    vector<int> ques1 = {0, 3, 5, 8, 9};
    vector<int> ques2 = {2, 1, 4, 6, 9};
    cout << minSwap(ques1, ques2);
    return 0;
}