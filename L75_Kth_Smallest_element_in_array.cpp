#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<int> input, int k)
{
    priority_queue<int> maxHeap; // Ek max heap bnali

    for (int i = 0; i < k; i++) // yaha pehle k elements ko heap me daal diya 
        maxHeap.push(input[i]);

    for (int i = k; i < input.size(); i++) // yaha rest elements ko comapre kar rahe hai heap ke
    {                                      // top se aur fir processing kar rahe hai
        if (input[i] < maxHeap.top())
        { 
            maxHeap.pop();
            maxHeap.push(input[i]);
        }
    }
    //  yaha aane ke baad first k small elements heap me aajayenge 
    return maxHeap.top(); // ab ye max heap hai to heap ke top pe hi k-th largest element  hoga
}

int main()
{
    vector<int> ques = {7, 10, 4, 20, 15};
    int k = 4;
    cout << "The " << k << "th smallest element in array is : " << kthSmallest(ques, k) << endl;
    return 0;
}