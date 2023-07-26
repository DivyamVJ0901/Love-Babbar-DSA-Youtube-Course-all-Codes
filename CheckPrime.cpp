#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= n - 1; i++)
    {
        if (n % i == 0)
        {
            cout << "It is Not Prime for " << i << endl;
        }

        else
        {
            cout<<"It is Prime Number for "<<i<<"."<<endl;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the value of n : " << endl;
    cin >> n;

    isPrime(n);
    return 0;
}