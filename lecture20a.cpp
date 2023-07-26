// CODE TO REVERSE AN ARRAY
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Reverse(vector<int> Divyam)
{
    int s = 0;
    int e = Divyam.size() - 1;
    while (s <= e)
    {
        swap(Divyam[s], Divyam[e]);
        s++;
        e--;
    }

    return Divyam;
}

void PrintArray(vector<int> Divyam)
{
    for (int i = 0; i < Divyam.size(); i++)
    {
        cout << Divyam[i] << " ";
    }
}
int main()
{
    vector<int> Divyam;
    Divyam.push_back(10);
    Divyam.push_back(06);
    Divyam.push_back(01);
    Divyam.push_back(56);
    Divyam.push_back(43);
    Divyam.push_back(23);
    cout << "The formed array is : ";
    PrintArray(Divyam);
    cout << endl;
    cout << "The Reversed array is : ";
    vector<int> Final_ans = Reverse(Divyam);
    PrintArray(Final_ans);
    return 0;
}