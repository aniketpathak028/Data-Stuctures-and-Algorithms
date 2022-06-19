// Prim's Algorithm is used to construct the Minimum Spanning Tree from a given graph


// Brute Force Approach - without any optimization
// Time Complexity = O(n^2)+
// Space Complexity = O(n)
#include <bits/stdc++.h>

using namespace std;

vector<int> MST(vector<pair<int, int>> adj[], int n)
{
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, 0);
    vector<int> parent(n, -1);

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n - 1; ++i){

        int mini = INT_MAX;
        int u;
        for (int j = 0; j < n; ++j){
            if(mst[j]==false && key[j]<mini){
                u = j;
                mini = key[j];
            }
        }
        mst[u] = true;

        for(auto it: adj[u]){
            if(mst[it.first]==false && it.second<key[it.first]){
                key[it.first] = it.second;
                parent[it.first] = u;
            }
        }
    }

    return parent;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    while (m--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    cout << "The Minimum Spanning Tree (MST) for the given graph is: ";
    auto ans = MST(adj, n);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}