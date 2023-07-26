#include <iostream>
#include <queue>
using namespace std;

int MinimumCost(vector<int> &arr)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < arr.size(); i++)
        minHeap.push(arr[i]);

    int sum = 0;
    while (minHeap.size() > 1)
    {
        int a = minHeap.top();
        minHeap.pop();
        int b = minHeap.top();
        minHeap.pop();

        int ans = a + b;
        sum += ans;
        minHeap.push(ans);
    }
    return sum;
}

int main()
{
    vector<int> input = {4, 2, 3, 6};
    cout << "The minimum cost of ropes is : " << MinimumCost(input) << endl;
    return 0;
}