#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V , vector<vector<int>> adj[] , int S)
{
    // Creation of Min Heap
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> min_heap;
    vector<int> dist(V , 1e9);

    dist[S] = 0;
    min_heap.push({0 , S});

    while(!min_heap.empty())
    {
        int distance = min_heap.top().first;
        int node = min_heap.top().second;
        min_heap.pop();

        for(auto it : adj[node])
        {
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(distance + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = distance + edgeWeight;
                min_heap.push({dist[adjNode] , adjNode});
            }
        }
    }
    return dist;
}

void Print(vector<int> arr)
{
    cout << "{";
    for (int i = 0; i < arr.size(); i++)
        cout
            << arr[i] << ",";
    cout << "}" << endl;
}

int main()
{
    vector<vector<int>> ques[] =  {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
    vector<int> ans = dijkstra(3 , ques ,   2);
    Print(ans);
    return 0;
}