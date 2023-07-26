#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;

    switch (n)
    {
    case 1 :
        cout<<"Hemlo Vimdhayak ji !"<<endl;
        break;

    case 2:
        cout<<"Kya re Dogesh kaisa hai ?"<<endl;
        break;

    case 3:
        cout<<"Mai to bamdiya hu Vimdhayak ji ??"<<endl;
        break;

    case 4:
        cout<<"Dogesh maine suna hai tere croro ka buisness hai ,Sahi me ??"<<endl;
        break;

    case 5 :
        cout<<"Are Vimadhayak ji , Croro ka nahi Pakodo ka bola tha."<<endl;
        break;
    
    default:
        cout<<"Cheems and Dogesh memes."<<endl;
        break;
    }

    return 0;
}