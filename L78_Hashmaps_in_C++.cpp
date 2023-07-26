#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
    // CREATION
    unordered_map<string, int> vijay;

    // INSERTION
    // Type 1 :
    pair<string, int> name = make_pair("Divyam", 4);
    vijay.insert(name);

    // Type 2 :
    pair<string, int> name2 = make_pair("Megha", 5);
    vijay.insert(name2);

    // Type 3:
    vijay["Divyam"] = 4;

    // Yaha updation hoti hai hamesha ,, kabhi bhi duplicate values nahi milegi
    vijay["Divyam"] = 10;

    // Searching
    cout << vijay.at("Megha") << endl;
    cout << vijay["Divyam"] << endl;

    // cout<<vijay.at("Shobhit")<<endl; // isko run krne se error show hoga kyuki ye memory hamne create nahi ki
    
    cout<<vijay["Shobhit"]<<endl; // Aisa Karne se ek memory create hojaati hai 0 ke corresponding
    cout<<vijay.at("Shobhit")<<endl; // Ab yaha bhi 0 show hoga

    // Size
    cout<<vijay.size()<<endl;

    // Present or Not
    cout<<vijay.count("Bansal")<<endl; // Absent to 0
    cout<<vijay.count("Divyam")<<endl; // Present to 1

    // Erase
    vijay.erase("Megha");
    cout<<vijay.size()<<endl;

    // Iterator
    unordered_map<string , int> :: iterator it = vijay.begin();

    while (it != vijay.end())
    {
        cout<<it->first << " "<<it->second<<endl;
        it++;
    }
     
    // Ans may be random order me aa skta hai kyuki unordered map bnaya hai 
    // Agar sirf map banaya hota to orderwise print hota
    return 0;
}