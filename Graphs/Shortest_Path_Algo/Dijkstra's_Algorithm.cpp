#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;

vector<int> dijkstra(vector<pair<int, int>> adj[], int n, int src)
{
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    vector<int> dist(n, 1e9);
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        int dis = node.first, val = node.second;
        for(auto &it: adj[val]){
            if(dis+it.second<dist[it.first]){
                dist[it.first] = dis + it.second;
                pq.push({dis + it.second, it.first});
            }
        }
    }
    return dist;
}

int main()
{
    int n, m, src;
    cin >> n >> m >> src;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    auto ans = dijkstra(adj, n, src);
    cout << "The shortest distance from src " << src << " to all nodes is: " << endl;
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}