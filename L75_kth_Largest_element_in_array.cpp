#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<int> input, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap; // Ek min heap bnali

    for (int i = 0; i < k; i++) // yaha pehle k elements ko heap me daal diya
        minHeap.push(input[i]);

    for (int i = k; i < input.size(); i++) // yaha rest elements ko comapre kar rahe hai heap ke
    {                                      // top se aur fir processing kar rahe hai
        if (input[i] > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(input[i]);
        }
    }
    //  yaha aane ke baad first k large elements heap me aajayenge
    return minHeap.top(); // ab ye min heap hai to heap ke top pe hi smallest element hoga
}

int main()
{
    vector<int> ques = {7, 10, 4, 20, 15};
    int k = 4;
    cout << "The " << k << "th largest element in array is : " << kthSmallest(ques, k) << endl;
    return 0;
}