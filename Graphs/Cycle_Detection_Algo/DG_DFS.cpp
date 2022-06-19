#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int i, vector<bool> &vis, vector<bool> &dfs_vis, vector<int> adj[])
{
    vis[i] = 1;
    dfs_vis[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            if (checkCycle(it, vis, dfs_vis, adj))
                return true;
        }
        else if (dfs_vis[it])
            return true;
    }
    dfs_vis[i] = 0;
    return false;
}

bool isCycle(int n, vector<int> adj[])
{
    vector<bool> vis(n, 0);
    vector<bool> dfs_vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, vis, dfs_vis, adj))
                return true;
        }
    }
    return false;
}

int main()
{
    // input graph
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << "The graph has cycle ? " << isCycle(n, adj);
    return 0;
}