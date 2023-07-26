#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Hero
{
public:
    int health;
    char level;
    char *name;

    // SIMPLE CONSTRUCTOR
    Hero()
    {
        cout << "This is a simple constructor" << endl;
        name = new char[100];
    }

    // PARAMETRIZED CONSTRUCTOR
    Hero(int health, char level)
    {
        this->health = health;
        this->level = level;
    }

    // COPY CONSTRUCTOR
    Hero(Hero &temp)
    {
        char *ch = new char[(strlen(temp.name)) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        cout << "This is a copy constructor" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }
    // SETTER
    void SetHealth(int h)
    {
        health = h;
    }
    void SetLevel(char ch)
    {
        level = ch;
    }
    void SetName(char name[])
    {
        strcpy(this->name, name);
    }

    static int time;

    static int random(){ // it can only acess static type data
        return time;
    }

    void Print()
    {
        cout << endl;
        cout << "NAME : " << this->name << " , ";
        cout << "HEALTH: " << this->health << " , ";
        cout << "LEVEL : " << this->level << endl
             << endl;
    }

    ~Hero()
    {
        cout << "This is a destructor" << endl;
    }
};

int Hero :: time = 60;

// NOTE : EMPTY CLASS ME SIZE OF CLASS 1 HOTA HAI

// int main()
// {

//     Hero Pan_Indian_Star;
//     char name[15] = "Allu Arjun";
//     Pan_Indian_Star.SetName(name);
//     Pan_Indian_Star.SetHealth(100);
//     Pan_Indian_Star.SetLevel('A');

//     Hero South_Star(Pan_Indian_Star);
//     Pan_Indian_Star.name[0] = 'B';
//     Pan_Indian_Star.Print();
//     South_Star.Print();

//     Pan_Indian_Star = South_Star; // Here '=' works as a copy assignment operator
//     Pan_Indian_Star.Print();
//     South_Star.Print();

//     // Hero Yash;
//     // // cout << "Size of : " << sizeof(Yash) << endl;
//     // // cout << "Total movies of yash in his career : " << Yash.movies << endl;

//     // Yash.SetMovies(50000);
//     // cout << Yash.GetMovies() << endl;

//     // Hero AA(Yash);
//     return 0;
// }

// int main()
// {
//     // Static allocation
//     Hero Vijay;

//     // Dynamic allocation
//     Hero *Yash = new Hero;
//     delete Yash;

//     // static memory allocation me destructor automatically call hota hai
//     // Jabki DMA me destructor ko manually call krana padta hai
//     return 0;
// }

int main()
{
    cout<<Hero :: time<<endl;
    cout<<Hero:: random()<<endl;
    return 0;
}