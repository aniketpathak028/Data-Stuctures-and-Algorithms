#include <bits/stdc++.h>
using namespace std;

// T.C = O(V+E) , S.C = O(V+2E) + O(V)
vector<int> bfs(int n, vector<int> adj[])
{
    vector<int> vis(n), ans;
    for (int i = 0; i < n; ++i){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto &it: adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return ans;
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

    auto ans = bfs(n, adj);

    // print bfs
    for(auto &it: ans)
        cout << it << " ";

    return 0;
}