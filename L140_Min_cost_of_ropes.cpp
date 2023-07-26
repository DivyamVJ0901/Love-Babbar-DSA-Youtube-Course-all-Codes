#include <bits/stdc++.h>
using namespace std;

long long minCost(vector<int> arr, int n)
{
    long long cost = 0;

    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for (int i = 0; i < arr.size(); i++)
        minHeap.push(arr[i]);

    while (minHeap.size() > 1)
    {
        long long first = minHeap.top();
        minHeap.pop();

        long long second = minHeap.top();
        minHeap.pop();

        cost = cost + first + second;

        minHeap.push(first + second);
    }

    return cost;
}

int main()
{
    vector<int> ques = {4,3,2,6};
    long long ans = minCost(ques , ques.size());
    cout<<ans;
    return 0;
}