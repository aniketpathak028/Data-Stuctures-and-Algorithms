// Disjoint Set implementation (union by rank and path compression)
#include <iostream>
using namespace std;

int Parent[100000];
int Rank[100000];

// 2 -> 3 -> 7 -> 9
int FindPar(int node)
{
    if (node == Parent[node])
        return node;
    return Parent[node] = FindPar(Parent[node]);
}

void MakeSet(int m)
{
    for (int i = 1; i <= m; ++i)
    {
        Parent[i] = i;
        Rank[i] = 0;
    }
}

void Union(int u, int v)
{
    int u = FindPar(u);
    int v = FindPar(v);

    if (Rank[u] < Rank[v])
    {
        Parent[u] = v;
    }
    else if (Rank[v] < Rank[u])
    {
        Parent[v] = u;
    }
    else
    {
        Parent[u] = v;
        Rank[u]++;
    }
}

int main()
{
    int m;
    cin >> m;
    MakeSet(5);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    return 0;
}