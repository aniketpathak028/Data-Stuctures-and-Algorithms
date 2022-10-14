// Graph-Representation ( Adjacency Matrix,  Adjacency List )

#include <bits/stdc++.h>
using namespace std;

// Undirected Graph
void adjacency_matrix() // S.C = O(n*n) [n = no. of vertices/nodes]
{
    int n, m;
    cin >> n >> m;
    int adj[n][n]; // assuming 0 based indexing
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

void adjacency_list() // S.C = O(n+2*m) [n = no. of vertices/nodes, m = no. of edges]
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

// Directed Graph with weights
void adjacency_list_wt() // S.C = O(n+2*m)
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1]; // vector of pair to store the wt
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // only push v into u because the graph is directed
    }
}

int main()
{
    cout << "*** Graph Representation using Adjacency Matrix && Adjacency List ***" << endl;
    adjacency_matrix();
    adjacency_list();
    return 0;
}