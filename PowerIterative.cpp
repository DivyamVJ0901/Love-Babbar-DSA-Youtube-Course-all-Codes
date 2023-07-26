#include <iostream>
using namespace std;

int power(int num1 , int num2)
{
    // int a, b;
    cout << "Enter the value of num1: " << endl;
    cin >> num1;
    cout << "Enter the value of num2: " << endl;
    cin >> num2;
    int ans = 1;
    for (int i = 1; i <= num2; i++)
    {
        ans = ans * num1;
    }
    return ans;
}

int main()
{
    int a , b;
    int z = power(a,b);

    cout << "The value of a rays to the power b is " << z << endl;
    return 0;
}

//----------* IMPORTANT POINTS *-----------
// Yaha pe agar hum power fun me cout<<a<<endl; lagaye to error aayega kyuki a main() function ka local variable hai isliye a ko main ke
// alawa koi dusra a ko function acess nahi kar skta.