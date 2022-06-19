#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            dfs(it, vis, st, adj);
        }
    }
    st.push(i);
}

vector<int> topological_sort(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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

    auto ans = topological_sort(n, adj);
    cout << endl;
    for (auto it : ans)
        cout << it << " ";
    return 0;
}