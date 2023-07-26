#include <iostream>
using namespace std;

inline int MaxNum(int &a, int &b)
{

    cout<<"enter value of a : "<<endl;
    cin>>a;
    cout<<"enter value of a : "<<endl;
    cin>>b;
    a++;
    b--;
    if (a > b)
        cout << a << endl;
    else
        cout << b << endl;
}

// #define pie 3.56
int main()
{
    // float r = 6.25;
    // float area = pie*r*r;
    // cout<<"Area is "<<area<<endl;

    int a = 50, b = 75;
    int ans = MaxNum(a, b);
    return 0;
}
