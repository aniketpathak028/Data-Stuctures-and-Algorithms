#include<bits/stdc++.h>
using namespace std;
// T.C = O(V+E) , S.C = O(V)+O(V+E)+O(E) [V = No. of vertices, E = No. of Edges]
vector<int> BFS(int V, vector<int> adj[]){
    vector<int> bfs;
    vector<int> vis(V, 0);
    queue<int> q;
    for (int i = 0; i < V; i++){
        if(!vis[i]){
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it: adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
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
    
    // BFS of graph driver-code
    auto ans = BFS(n, adj);
    cout << "BFS of the graph is: " << endl;
    for (auto it: ans)
        cout << it << " ";
    return 0;
}