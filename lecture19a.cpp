#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 4> Divyam = {10, 6, 17, 43};
    int size = Divyam.size();
    for (int i = 0; i < 4; i++)
    {
        cout << Divyam[i] << " ";
    }
    cout << endl
         << size << endl;

    cout << "Element at 2nd index : " << Divyam.at(2) << endl;
    if (Divyam.empty() == 1)
    {
        cout << "empty";
    }
    else
    {
        cout << "Not Empty";
    }

    return 0;
}