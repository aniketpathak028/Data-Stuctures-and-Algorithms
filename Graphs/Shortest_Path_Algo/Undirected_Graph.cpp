#include <bits/stdc++.h>
using namespace std;

vector<int> shortest_path(vector<int> adj[], int src, int n)
{
    // distance vector to store the shortest distance of all nodes from source
    vector<int> dist(n);
    // initialize to infinity
    for (int i = 0; i < n; ++i)
        dist[i] = INT_MAX;

    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        for(auto &it: adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    return dist;
}

int main()
{
    // Take Graph input
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto ans = shortest_path(adj, 0, n);

    // print shortest distance of all nodes from source node

}