// Kahn's Algorithm is the BFS Algorithm to find the topological sort of a DAG (Directed Acyclic Graph)

#include<bits/stdc++.h>

using namespace std;

vector<int> BFS(int V, vector<int> adj[]){
    vector<int> ans;
    queue<int> q;
    vector<int> indegree(V);
    for (int i = 0; i < V; i++)
        for(auto it: adj[i]){
            indegree[it]++;
        }
    for (int i = 0; i < V; i++){
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto it: adj[node]){
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
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

    auto ans = BFS(n, adj);
    cout << endl;
    for (auto it : ans)
        cout << it << " ";
    return 0;
}