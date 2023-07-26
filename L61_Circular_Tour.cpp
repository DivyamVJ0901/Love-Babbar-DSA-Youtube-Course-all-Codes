#include <bits/stdc++.h>
using namespace std;

class PetrolPump
{
public:
    int petrol;
    int distance;
    PetrolPump(int p, int d)
    {
        this->petrol = p;
        this->distance = d;
    }
};

int tour(PetrolPump p[], int n)
{
    int deficiency = 0;
    int balance = 0;
    int starting_point = 0;
    
    for (int i = 0; i < n; i++)
    {
        balance = balance + p[i].petrol - p[i].distance;
        if(balance < 0)
        {
            deficiency = deficiency + balance; // Deficiency me jod liya kyuki negative balance hai 
            starting_point = i + 1;
            balance = 0; 
        }
    }

    if(deficiency + balance >= 0)
        return starting_point;
    return -1;
}



int main()
{
    
    return 0;
}