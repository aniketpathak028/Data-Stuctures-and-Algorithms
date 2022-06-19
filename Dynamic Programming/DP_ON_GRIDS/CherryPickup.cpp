#include <bits/stdc++.h>

using namespace std;

int solve(int i1, int j1, int i2, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<vector<int>>>> &dp)
{
    // out-of-bound condition
    if (i1 >= r || i2 >= r || j1 >= c || j2 >= c || grid[i1][j1] == -1 || grid[i2][j2] == -1)
        return -1e8;

    // base condition
    if (i1 == r - 1 && j1 == r - 1 && i2 == c - 1 && j2 == c - 1)
        return grid[r - 1][c - 1];

    if (dp[i1][j1][i2][j2] != -1)
        return dp[i1][j1][i2][j2];

    int value = grid[i1][j1];
    if (i1 != i2)
        value += grid[i2][j2];

    int temp = max({solve(i1 + 1, j1, i2 + 1, j2, r, c, grid, dp), solve(i1 + 1, j1, i2, j2 + 1, r, c, grid, dp), solve(i1, j1 + 1, i2 + 1, j2, r, c, grid, dp), solve(i1, j1 + 1, i2, j2 + 1, r, c, grid, dp)});
    value += temp;
    return dp[i1][j1][i2][j2] = value;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<vector<vector<int>>>> dp(r, vector<vector<vector<int>>>(c, vector<vector<int>>(r, vector<int>(c, -1))));

    return max(0, solve(0, 0, 0, 0, r, c, grid, dp));
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];
    }
    cout << cherryPickup(grid);
    return 0;
}