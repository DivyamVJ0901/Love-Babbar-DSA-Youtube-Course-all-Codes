// CONCEPT OF REFERENCE VARIABLES

#include <iostream>
using namespace std;

void update(int n)
{
    n++;
}
void update1(int &n)
{
    n++;
}

int &func(int n)
{
    int num = n;
    int &ans = n;
    return ans;
}

int *func1(int n)
{
    int num = n;
    int *ans = &n;
    return ans;
}

int getSum(int *arr , int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    
    return sum;
}

int main()
{
    /*
    int n = 58;
    cout << n << endl;
    update(n);
    cout << n << endl;
    cout << n << endl;
    update1(n);
    cout << n << endl;

    cout << func(n); // It gives warning kyuki yaha pe kuch memory ka locha hai
    cout << func1(n); // Same yha bhi 
    */

    /*
    int n; 
    cout<<"Enter array size : ";
    cin>>n;
    int *Cheemda = new int[n];

    for (int i = 0; i < n; i++)
        cin>>Cheemda[i];


    int ans = getSum(Cheemda , n);
    cout<<"answer is : "<<ans<<endl;
    */

    char ch = 'a';

    char *c =  &ch;
    cout<<sizeof(ch)<<endl;
    cout<<sizeof(c)<<endl;
    
    return 0;
}