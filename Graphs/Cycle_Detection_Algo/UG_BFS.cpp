#include <bits/stdc++.h>

using namespace std;

bool checkCycle(int i, int n, vector<int> &vis, vector<int> adj[])
{
    queue<pair<int, int>> q;
    q.push({i, -1});
    vis[i] = 1;
    while (!q.empty())
    {
        auto node = q.front().first;
        auto prev = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push({it, node});
                vis[it] = 1;
            }
            else if (it != prev)
                return true;
        }
    }
    return false;
}

bool isCycle(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && checkCycle(i, n, vis, adj))
            return true;
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

    cout<< "The graph has cycle ? " << isCycle(n, adj);
    return 0;
}