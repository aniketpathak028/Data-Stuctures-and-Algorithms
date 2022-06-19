#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int V, vector<int> adj[], int src){
    vector<int> dist(V, INT_MAX);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
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
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto ans = bfs(n, adj, 5);
    return 0;
}