#include<iostream>
using namespace std;

void goingToCollege(int h , int c)
{
    cout<<"Home "<<h<<" College "<<c<<endl;
    if (h == c)
    {
        cout<<"Reached"<<endl;
        return ;
    }
    h++;
    return goingToCollege(h , c);
}

int main()
{   
    int a = 50;
    int b = 70;
    goingToCollege(a , b);
    
    return 0;
}