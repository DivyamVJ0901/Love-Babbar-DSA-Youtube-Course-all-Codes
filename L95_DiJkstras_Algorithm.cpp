#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adjlist;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adjlist[u].push_back(make_pair(v, w));
        adjlist[v].push_back(make_pair(u, w));
    }

    // creation of Distance array initialised with int_max
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++) dist[i] = INT_MAX;

    // Creation of set
    set<pair<int, int>> st;

    // make src_node distance equal to 0
    dist[source] = 0;

    // insert src_node record
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        // fetch top record
        auto top = *(st.begin());
        int distance = top.first;
        int node = top.second;

        st.erase(st.begin());

        for (auto neighbour : adjlist[node])
        {
            if (distance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                if (record != st.end())
                {
                    st.erase(record);
                }
                dist[neighbour.first] = distance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
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
    vector<vector<int>> ques = {{0, 1, 5}, {0, 2, 8}, {1, 2, 9}, {1, 3, 2}, {2, 3, 6}};
    vector<int> ans = dijkstra(ques, 4, 5, 0);
    Print(ans);
    return 0;
}