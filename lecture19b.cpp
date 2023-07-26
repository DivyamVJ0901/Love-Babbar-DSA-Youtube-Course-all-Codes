#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<int> Divyam;
    // Divyam.push_back(45);
    // Divyam.push_back(48);
    // Divyam.push_back(15);
    // Divyam.push_back(95);
    // Divyam.push_back(56);
    // Divyam.push_back(32);
    // cout << "Elment at 3rd position is " << Divyam.at(2) << endl;
    // cout << "front element is : " << Divyam.front() << endl;
    // cout << "last element is : " << Divyam.back() << endl;
    // cout << "Size of array is : " << Divyam.size();
    // cout << endl;
    // cout << "Capacity of array is : " << Divyam.capacity();
    // cout << endl;
    // cout << "The formed array is : ";
    // for (int i = 0; i < Divyam.size(); i++)
    // {
    //     cout << Divyam[i] << " ";
    // }
    // cout << endl;

    // Divyam.pop_back();
    // Divyam.pop_back();
    // Divyam.pop_back();
    // Divyam.pop_back();
    // Divyam.pop_back();
    // Divyam.pop_back();
    // cout << "The formed array is : ";
    // for (int i = 0; i < Divyam.size(); i++)
    // {
    //     cout << Divyam[i] << " ";
    // }

    // cout<<"Before clear size : "<<Divyam.size()<<endl;
    // Divyam.clear();
    // cout<<"after clear size : "<<Divyam.size()<<endl;

    vector<int> Megha(6 , 2);
    vector<int> Divyam(Megha);
    cout<<"Printed MEgha array is : ";
    for (int i = 0; i < Divyam.size(); i++)
    {        
        cout << Divyam[i] << " ";
    }
    return 0;
}