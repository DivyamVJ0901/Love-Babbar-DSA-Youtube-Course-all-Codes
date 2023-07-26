#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    vector<int>Divyam;
    Divyam.push_back(56);
    Divyam.push_back(17);
    Divyam.push_back(43);
    Divyam.push_back(10);
    Divyam.push_back(06);
    Divyam.push_back(01);
    Divyam.push_back(89);

    Divyam.push_back(45);
    Divyam.push_back(21);
    Divyam.push_back(23);

    for (int i = 0; i < Divyam.size(); i++)
    {
        cout<<Divyam[i]<<" ";
    }
    cout<<endl;
    cout<<binary_search(Divyam.begin() , Divyam.end() , 17);   
    // cout<<sort(Divyam.begin() , Divyam.end());
    return 0;

}