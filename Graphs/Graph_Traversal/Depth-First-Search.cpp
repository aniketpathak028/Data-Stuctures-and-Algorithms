#include <bits/stdc++.h>
using namespace std;

// T.C = O(V+E) , S.C = O(V+2E) + O(V)
void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans)
{
    vis[node] = 1;
    ans.push_back(node);
    for (auto &it : adj[node])
    {
        if (!vis[it])
            dfs(it, adj, vis, ans);
    }
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

    vector<int> ans;
    vector<int> vis(n);
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, ans);
        }
    }

    // print dfs
    for (auto &it : ans)
        cout << it << " ";

    return 0;
}