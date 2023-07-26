#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;

    return n * fact(n - 1);
}

int Power(int a, int b)
{
    if (b == 0)
        return 1;
    return a * Power(a, b - 1);
}

void Count(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    Count(n - 1);
}

void Count1(int n)
{
    if (n == 0)
        return;
    Count1(n - 1);
    cout << n << " ";
}

int main()
{
    // int a;
    // cin>>a;
    // int ans = fact(a);

    // cout<<ans<<endl;

    // int a, b;
    // cin >> a >> b;

    // int ans = Power(a, b);
    // cout << ans << endl;

    int m;
    cin >> m;
    Count(m);
    cout<<endl;
    Count1(m);
    return 0;
}