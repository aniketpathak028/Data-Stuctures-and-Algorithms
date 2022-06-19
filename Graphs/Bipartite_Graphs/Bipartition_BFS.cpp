#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int V, m;
vector<int> vis(1001, -1);

void input_graph()
{
    cin >> V >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool bfsB(int i){
    queue<pair<int, int>> q;
    q.push({i, -1});
    vis[i] = 0;
    while(!q.empty()){
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();
        for(auto it: adj[node]){
            if(vis[it]==-1){
                vis[it] = vis[node] == 1 ? 0 : 1;
                q.push({it, node});
            }
            else if(vis[it]==vis[node])
                return false;
        }

    }
    return true;
}

bool checkBipartition()
{
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == -1)
        {
            if (!bfsB(i))
                return false;
        }
    }
    return true;
}

int main()
{
    input_graph();
    cout << checkBipartition();
    return 0;
}