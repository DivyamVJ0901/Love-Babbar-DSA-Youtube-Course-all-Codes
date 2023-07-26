// FINDING SQUARE ROOT USING BINARY SEARCH
#include <iostream>
using namespace std;

int Squareroot(int arr[], int num)
{
    int s, e, mid, ans;
    s = 0;
    e = num - 1;
    ans = mid;
    mid = s + (e - s) / 2;
    while (s <= e)
    {
        if ((mid * mid) == num)
        {
            return mid;
        }
        else if ((mid * mid) < num)
        {
            ans = mid;
            s = mid + 1;
        }
        else if ((mid * mid) > num)
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

double accuracy(int n, int prec, int tempSoln)
{
    double factor = 1;
    double ans1 = tempSoln;
    for (int i = 0; i < prec; i++)
    {
        factor = factor / 10;

        for (double j = 0; j * j < n; j = j + factor)
        {
            ans1 = j;
        }
    }
    return ans1;
}
int main()
{
    cout << "NOTE - Ans may not be perfect but it is the nearest integer from the expected answer." << endl;
    int b;
    cout << "Enter a number here : ";
    cin >> b;
    int tempSoln;

    int Divyam[b];
    for (int i = 0; i <= b; i++)
    {
        i;
    }
    double more_precise_sqr_rt = accuracy(b, 5, tempSoln);
    int sq_rt = Squareroot(Divyam, b);
    cout << "The sqaure root of " << b << " is : " << sq_rt << endl;
    cout << "The more precise sqaure root of " << b << " is : " << more_precise_sqr_rt << endl;

    return 0;
}