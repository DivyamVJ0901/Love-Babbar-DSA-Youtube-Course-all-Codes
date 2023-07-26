#include <bits/stdc++.h>
using namespace std;

int minDays(int s, int n, int m)
{
    if(n < m)
        return -1;
    // ans variable me ans store krenge
    int ans = 0;

    // Sundays ke din dukaan band rahegi isiye
    int sundays = s / 7;
    
    // Sirf inhi dino me buy kar skte hai 
    int buyingDays = s - sundays;

    // Survive karne ke liye totally itna food chahiye hoga
    int totalfood = s * m;

    if (totalfood % n == 0)
        ans = totalfood / n;
    else
        ans = totalfood / n + 1;

    // Special case : Jab 
    if (ans <= buyingDays)
        return ans;
    return -1;
}

int main()
{
    int S = 10, N = 16, M = 2;
    cout << minDays(S, N, M);
    return 0;
}