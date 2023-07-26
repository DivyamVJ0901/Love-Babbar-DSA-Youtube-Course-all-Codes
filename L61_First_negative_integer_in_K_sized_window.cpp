#include <bits/stdc++.h>
using namespace std;

vector<long long> negativeInKsizedWindow(long long int A[], long long int N, long long int K)
{
    deque<long long int> dq;
    vector<long long> ans;

    // Process first window of K size : K size ki window me jo jo negative numbers hai unke indices store kr liye
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            dq.push_back(i);
    }

    // Store the answer in Ans array :
    if (dq.size() > 0)
        ans.push_back(A[dq.front()]);
    else
        ans.push_back(0);

    // Travese for remaining windows :
    for (int i = K; i < N; i++)
    {
        // removal case : purana element htaane ke liye
        if ((!dq.empty()) && i - dq.front() >= K)
            dq.pop_front();

        // Addition case : naya element daalne ke liye
        if (A[i] < 0)
            dq.push_back(i);

        // Answer store krlo ab :
        if (dq.size() > 0)
            ans.push_back(A[dq.front()]);
        else
            ans.push_back(0);
    }
    return ans;
}

void Print(vector<long long> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;   
}

int main()
{
    long long int A[5] = {-8, 2, 3, -6, 10};
    vector<long long> ans = negativeInKsizedWindow(A, 5, 2);
    Print(ans);
    return 0;
}