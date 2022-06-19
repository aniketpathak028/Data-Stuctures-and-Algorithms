#include<bits/stdc++.h>
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

bool dfsB(int i, int prev){
    for(int it: adj[i]){
        if(vis[it]==-1){
            vis[it] = vis[i] == 1 ? 0 : 1;
            if(!dfsB(it, i))
                return false;
        } else if(vis[it]==vis[i])
            return false;
    }
    return true;
}

bool checkBipartition(){
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == -1)
        {
            if (!dfsB(i, -1))
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