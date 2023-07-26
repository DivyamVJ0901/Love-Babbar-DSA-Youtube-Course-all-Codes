// CODE TO REVERSE WORDS IN A STRING
#include "bits/stdc++.h"
using namespace std;

void Reverse(char a[], int s, int e)
{
    while (s < e)
    {
        swap(a[s++], a[e--]);
    }
}

string reverseWords(char a[])
{
    int s = 0, e = 0;
    int length = strlen(a);
    for (int i = 0; i <= length; i++)
    {
        if (a[i] == ' ' || a[i] == '\0')
        {
            Reverse(a, s, e - 1);
            s = e + 1;
        }
        e++;
    }
    return a;
}

int main()
{
    char s[] = "my name is Divyam Vijay";
    cout<<"The string is : "<<s<<endl;
    cout <<"The operated string is : "<< reverseWords(s) << endl;
    return 0;
}