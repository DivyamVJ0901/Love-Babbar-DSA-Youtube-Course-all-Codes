// BITWISE OPERATORS

#include <iostream>
using namespace std;
int main()
{
    // int a = 8;
    // int b = 10;
    // cout << "The value of a&b is : " << (a & b) << endl;
    // cout << "The value of a|b is : " << (a | b) << endl;
    // cout << "The value of ~a is : " << ~a << endl;
    // cout << "The value of a^b is : " << (a ^ b) << endl;

    // LEFT SHIFT AND RIGHT SHIFT OPERATOR
    // In Left and right shift operator ,padding always with 0.

    // cout << (17 >> 1) << endl;
    // cout << (54 >> 2) << endl;
    // cout << (19 << 4) << endl;
    // cout << (21 << 2) << endl;

    // FOR LOOP
    // int n;
    // cout<<"Enter the value of n : "<<endl;
    // cin >> n;
    // int i = 1;
    // for (; ;)
    // {
    //     if(i <= n){
    //     cout <<i<<" ";
    //     i++;
    //     }
    //     else{
    //         break;
    //         }

    // int n;
    // cout << "Enter the value of n : " << endl;
    // cin >> n;
    // for (int a = 1, b = 2; a <= n, b <= n; ++a, b++)
    // {
    //     cout << a << " " << b << endl;
    // }
    // ___________________________PROGRAM TO PRINT SUM OF FIRST N NUMBERS_______________________

    // ------>> USING FOR LOOP
    // int n;
    // cout << "Enter the value of n : " << endl;
    // cin >> n;
    // int sum = 0;
    // for (int i = 0; i <= n; i++)
    // {
    //     sum = sum + i;
    // }
    // cout << "The value  of sum is : " << sum;

    // ------>> USING WHILE LOOP
    // int n;
    // cout << "Enter the value of n : " << endl;
    // cin >> n;
    // int sum = 0;
    // int i=0;
    // while (i<=n)
    // {
    //     sum = sum + i;
    //     i++;
    // }
    // cout << "The value  of sum is : " << sum;

    // ___________________________PROGRAM TO PRINT PRIME NUMBER______________________

    int n;
    cout << "Enter the value of n : " << endl;
    cin >> n;
    for (int i = 2; i <= (n-1),i++;)
    {
        if(n%i==0){
            cout<<"Not a Prime Number."<<i<<endl;
            break;
        }
        else{
            cout<<"Its a prime number."<<i<<endl;
        }
    }

    return 0;
}

