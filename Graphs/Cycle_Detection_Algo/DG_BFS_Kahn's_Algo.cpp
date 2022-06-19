// Detecting Cycle in a graph using Kahn's Algorithm (BFS)
// DFS approach is a better solution of this problem as this approach isn't concrete, and is based on 
// reverse hypothesis that if a Graph has cycle in it, its toposort cannot be created.
#include <bits/stdc++.h>
using namespace std;

bool BFS(int V, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(V);
    for (int i = 0; i < V; i++)
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        cnt++;
        q.pop();
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return cnt == V ? false : true;
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

    auto ans = BFS(n, adj);
    cout << ans;
    return 0;
}