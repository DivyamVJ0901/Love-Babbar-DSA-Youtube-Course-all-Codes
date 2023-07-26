// CODE FOR REMOVING OCCURENCE OF A PARTICULAR PART OF A STRING
#include <iostream>
#include <vector>
using namespace std;

string removeOccurence(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}
int main()
{
    string str = "axxxxyyyyb";
    string part = "xy";
    cout << "The question string is : " << str << endl;
    cout << "The part string is : " << part << endl;
    cout << "The operated string is : " << removeOccurence(str, part) << endl;
    return 0;
}