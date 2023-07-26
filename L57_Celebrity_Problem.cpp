#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool knows(vector<vector<int>> &party, int a, int b, int n)
{
    if (party[a][b] == 1)
        return 1;
    return 0;
}

bool CelebrityOrNot(vector<vector<int>> &party, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
        s.push(i);

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(party, a, b, n))
            s.push(b);
        else
            s.push(a);
    }

    int ans = s.top();
    
    int count0 = 0 , count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (party[ans][i] == 0)
            count0++;
    }

    for (int i = 0; i < n; i++)
    {
        if (party[i][ans] == 1)
            count1++;
    }
    
    if (count0 == n && count1 == n-1)
        return ans;
    else 
        return -1;
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    cout<<"The celebrity out of 1,2,3 is : "<<CelebrityOrNot(mat , 3);
    return 0;
}