#include <bits/stdc++.h>

using namespace std;
// T.C = O(V+E) , S.C = O(V)+O(V+E)+O(E)
void DFS(int node, vector<bool> &vis, vector<int> adj[], vector<int> &dfs_store)
{
    dfs_store.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it])
            DFS(it, vis, adj, dfs_store);
}

int main()
{
    // creating an adjacency-list (taking a graph as input)
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

    // DFS of graph driver-code
    vector<int> dfs_store;
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++){
        if(!vis[i]) DFS(i, vis, adj, dfs_store);
    }
    cout << "DFS of the graph is: " << endl;
    for (auto it : dfs_store)
        cout << it << " ";
    return 0;
}