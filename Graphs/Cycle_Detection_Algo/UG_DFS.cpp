#include <bits/stdc++.h>

using namespace std;

bool checkCycle(int i, int prev, vector<bool> &vis, vector<int> adj[])
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it]){
            if (checkCycle(it, i, vis, adj))
                return true;
        }
        else if (it != prev)
            return true;
    }
    return false;
}

bool isCycle(int n, vector<int> adj[])
{
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i]){
            if (checkCycle(i, -1, vis, adj))
                return true;
        }
    }
    return false;
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

    // input
    // 5 6 0 1 0 2 1 3 2 3 1 4 3 4

    cout << "The graph has cycle ? " << isCycle(n, adj);
    return 0;
}