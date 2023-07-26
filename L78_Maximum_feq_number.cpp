#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> cnt;

    int maxFreq = 0;
    int maxAns = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        cnt[arr[i]]++;
        maxFreq = max(maxFreq, cnt[arr[i]]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (maxFreq == cnt[arr[i]])
        {
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;
}

int main() 
{
    vector<int> ques = {2, 12, 2, 11, -12, 2, -1, 2, 2, 11, 12, 2, -6};
    cout << "The number occurs maximum no. of times is : " << maximumFrequency(ques, ques.size())<<endl;
    return 0;
}