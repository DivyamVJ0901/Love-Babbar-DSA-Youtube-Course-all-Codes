// CODE FOR REVERSING A STRING
#include <iostream>
#include <vector>
using namespace std;

string reverse(string str)
{
    int s = 0;
    int e = str.length() - 1;
    while (s <= e)
    {
        swap(str[s++], str[e--]);
    }
    cout<<"The reversed string is : "<<str;
}

int main()
{
    string s = "My name is Divyam Vijay.";
    cout << "Your string is : " << s << endl;
    reverse(s);
    return 0;
}