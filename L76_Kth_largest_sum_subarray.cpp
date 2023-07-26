#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// TC : O(n^2.log(n))
// SC : O(n^2)
int kthLargestSumSubarray(vector<int> &nums, int k)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            ans.push_back(sum);
        }
    }
    sort(ans.begin(), ans.end());
    return ans[ans.size() - k];
}

// OPTIMIZED APPROACH : SC :- O(k)
int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (minHeap.size() < k)
                minHeap.push(sum);
            else
            {
                if (sum > minHeap.top())
                {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }
    return minHeap.top();
}

int main()
{
    vector<int> ques = {4, 3, 5, 7, 8};
    cout << "Kth largest sum subarray is : " << kthLargestSumSubarray(ques, 4) << endl;
    cout << "Kth largest sum subarray is : " << getKthLargest(ques, 4) << endl;
    return 0;
}