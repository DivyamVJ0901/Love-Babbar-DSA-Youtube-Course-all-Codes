// CODE TO FIND GCD
#include<iostream>
using namespace std;

int gcd(int a , int b)
{
    if(a == 0)
    return b;

    if(b == 0)
    return a;

    while(a != b)
    {
        if (a > b)
            a = a-b;
        else
            b = b-a;
    }
    return a;
}

int main()
{
    int num1 , num2;
    cout<<"Enter the values of num1 and num2 : ";
    cin>>num1>>num2;
    cout<<"The entered numbers are : "<<num1 <<" and "<<num2<<endl;
    cout<<"The gcd of "<<num1<<" and "<<num2<<" is "<<gcd(num1 , num2 )<<endl;
    return 0;
}