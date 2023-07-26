// CODE TO REVERSE A STRING USING RECURSION
#include <iostream>
using namespace std;

void reverse(string &str, int s, int e)
{
    if (s > e)
        return;

    swap(str[s++], str[e--]);

    reverse(str, s, e);
}
 
int main()
{
    string name = "Divyam";
    cout << name << endl;
    reverse(name, 0, name.length() - 1);
    cout << name << endl;
    return 0;
}