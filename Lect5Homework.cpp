// QUESTION 1
#include <iostream>
using namespace std;

int main()
{
    int a, b = 1;
    a = 10;
    if (++a)
    {
        cout << b;
    }
    else
    {
        cout << ++b;
    }
    return 0;
}

// QUESTION 2
#include <iostream>
using namespace std;

int main()
{
    int a = 1;
    int b = 2;

    if (a-- > 0 && ++b > 2)
    {
        cout << "Stage1 - Inside If " << endl;
    }
    else
    {
        cout << "Stage2 - Inside else " << endl;
    }

    cout << "The final value of a & b is " << a << " & " << b << endl;
    return 0;
}

// QUESTION 3
#include <iostream>
using namespace std;

int main()
{
    int a = 1;
    int b = 2;

    if (a-- > 0 || ++b > 2)
    {
        cout << "Stage1 - Inside If " << endl;
    }
    else
    {
        cout << "Stage2 - Inside else " << endl;
    }

    cout << "The final value of a & b is " << a << " & " << b << endl;
    return 0;
}

// QUESTION 4
#include<iostream>
using namespace std;

int main(){
    int num = 3;
    cout<<(25*(++num));
    return 0;
}

// QUESTION 5
#include <iostream>
using namespace std;

int main()
{
    int a = 1;
    int b = a++;
    int c = ++a;
    cout<<b<<endl;
    cout<<c<<endl;
    return 0;
}

// QUESTION 6
#include<iostream>
using namespace std;

int main(){
    for (int i = 0; i <=5; i++)
    {
        cout<<i<<" ";
        i++;
    }

    return 0;
}

// QUESTION 7
 #include<iostream>
 using namespace std;

int main(){
    for (int i = 0; i <=5; i--)
    {
        cout<<i<<" ";
        i++;
    }

    return 0;
}

// QUESTION 8
#include<iostream>
using namespace std;

int main(){
    for (int i = 0; i <=15; i+=2)
    {
        cout<<i<<" ";
        if(i&1){
            continue;
        }
        i++;
    }

    return 0;
}

// QUESTION 9
#include<iostream>
using namespace std;

int main(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <=5; j++)
        {
            cout<<i<<" & "<<j<<endl;
        }

    }

    return 0;
}

// QUESTION 10
#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            if(i+j==10){
                break;
            }
            cout << i << " & " << j << endl;
        }
    }

    return 0;
}
