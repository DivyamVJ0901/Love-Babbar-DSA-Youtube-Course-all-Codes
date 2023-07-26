#include <bits/stdc++.h>
using namespace std;

class Job
{
public:
    int profit;   // Represents Profit for each job
    int deadline; // Represents deadline of job
    int id;       // Represents id of a job

    Job(int p, int d, int i)
    {
        this->profit = p;
        this->deadline = d;
        this->id = i;
    }
};

static bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    vector<int> ans;

    // Sort kar diya on the basis of their profit
    sort(arr, arr + n, cmp);

    // Maximum deadline nikalne ke liye jisse hum apna schedule array bna paayenge
    int maxiDeadline = INT_MIN;
    for (int i = 0; i < n; i++)
        maxiDeadline = max(maxiDeadline, arr[i].deadline);

    // Schedule array bnane ke liye
    vector<int> schedule(maxiDeadline + 1, -1);

    //
    int maximumProfit = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int currProfit = arr[i].profit;
        int currDeadline = arr[i].deadline;
        int currId = arr[i].id;

        for (int k = currDeadline; k > 0; k--)
        {
            if (schedule[k] == -1)
            {
                cnt++;
                maximumProfit += currProfit;
                schedule[k] = currId;
                break; // ans mil gya hoga ab tk so yaha break kr denge
            }
        }
    }

    ans.push_back(cnt);
    ans.push_back(maximumProfit);
    return ans;
}

void Print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{

    return 0;
}