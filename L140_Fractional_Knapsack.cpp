#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int value;
    int weight;
    Item(int v, int w)
    {
        this->value = v;
        this->weight = w;
    }
};

static bool cmp(pair<double, Item> a, pair<double, Item> b)
{
    return a.first > b.first;
}

double fracKnapsack(int W, Item arr[], int N)
{
    vector<pair<double, Item>> v;

    for (int i = 0; i < N; i++)
    {
        pair<double, Item> p = make_pair(((1.0) * arr[i].value) / arr[i].weight, arr[i]);
        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp);

    int totalValue = 0;

    for (int i = 0; i < N; i++)
    {
        // Sirf fraction le skta hu mei
        if (v[i].second.weight > W)
        {
            totalValue += W * v[i].first;
            W = 0;
        }

        // Yaha 1 le skta hu
        else
        {
            totalValue += v[i].second.value;
            W = W - v[i].second.weight;
        }
    }
    return totalValue;
}

int main()
{
    // int weight[3] = {60, 100, 120};
    // int value[3] = {10, 20, 30};
    // Item ques = new Item(weight[3], value[3]);
    // cout << fracKnapsack(3, ques, 5);
    return 0;
}