// CODE TO GET LENGTH OF A STRING
#include <iostream>
#include <vector>
using namespace std;

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    char name[20] = "Divyam";
    cout << "Your name is : " << name<<endl;
    int len = getLength(name);
    cout<<"The lenth of name is : "<<getLength(name);
    return 0;
}