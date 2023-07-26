#include <iostream>
using namespace std;

bool isEven()
{
    int n;
    cout << "Enter n :" << endl;
    cin >> n;
    if (n % 2 != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
};

int main()
{
    bool z = isEven();
    if (z == 1)
    {
        cout << "The entered number is even." << endl;
    }
    else
    {
        cout << "The enterd number is odd." << endl;
    }
    return 0;
}