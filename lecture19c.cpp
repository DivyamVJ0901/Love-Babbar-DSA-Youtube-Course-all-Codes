#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> Divyam;
    // Divyam.push_front(9);
    // Divyam.push_front(78);
    // Divyam.push_front(2); //Push front me neeche se uper ki trf print karna shuru hote hai.
    // Divyam.push_front(1); //Push back me uper se neeche ki trf elements print hote hai.
    // Divyam.push_front(8); // Jaise is case me front me sabse pehle 8 aayega , fir 1 , 2 , 78 , 9
    // Divyam.push_back(4); // Back me pehle 4 aayega fir 5
    // Divyam.push_back(5);

    // cout<<"Element at 4th index is : "<<Divyam.at(4)<<endl;
    // cout<<"The array is : ";
    // for (int i = 0; i < Divyam.size(); i++)
    // {
    //     cout<<Divyam[i]<<" ";
    // }
    // cout<<endl;

    // Divyam.pop_back(); // 5 delete hoga
    // Divyam.pop_front(); // 8 delete hoga
    // cout<<"The array is : ";
    // for (int i = 0; i < Divyam.size(); i++)
    // {
    //     cout<<Divyam[i]<<" ";
    // }
    // cout<<endl;

    int a, b, c, d;
    a = 12 , b = 13 , c = 14 , d = 15 ;
    deque<int>Megha;
    Megha.push_back(a);
    Megha.push_back(b);
    Megha.push_front(c);
    Megha.push_front(d);
    cout<<endl;
    for (int i = 0; i < Megha.size(); i++)
    {
        cout<<Megha[i]<<" ";
    }
    
    return 0;
} 