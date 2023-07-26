#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int signum(int a, int b)
{
    if (a == b)
        return 0;
    else if (a > b)
        return 1;
    else
        return -1;
}

void call_median(int element, priority_queue<int> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap, int &median)
{
    switch (signum(maxheap.size(), minheap.size()))
    {
    case 0:
        if (element > median)
        {
            minheap.push(element);
            median = minheap.top();
        }
        else
        {
            maxheap.push(element);
            median = maxheap.top();
        }
        break;
    case 1:
        if (element > median)
        {
            minheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        }
        else
        {
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        }
        break;

    case -1:
        if (element > median)
        {
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        }
        else
        {
            maxheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        }
        break;
    }
}

vector<int> findMedian(vector<int> &arr, int n)
{
    vector<int> res;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int median = 0;
    for (int i = 0; i < n; i++)
    {
        call_median(arr[i], maxHeap, minHeap, median);
        res.push_back(median);
    }
    return res;
}

void Print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> ques = {1, 2, 3};
    vector<int> ans = findMedian(ques, 3);
    Print(ans);
    return 0;
}