#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "011001";
    int cnt1 = 0;
    int cnt0 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '0')
            cnt0++;

        if(s[i] == '1')
            cnt1++;
    }
    
    int ans = min(cnt0 , cnt1);
    cout<<ans<<endl;
    return 0;
}