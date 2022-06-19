// https://leetcode.com/problems/dungeon-game/

#include <bits/stdc++.h>

using namespace std;

// dp
int solve(int i, int j, vector<vector<int>> &dungeon, int r, int c, vector<vector<int>> &dp)
{
    // out-of-bound condition
    if (i >= r || j >= c)
        return 1e8;

    // base-case
    if (i == r - 1 && j == c - 1)
        return dungeon[r - 1][c - 1] < 0 ? -dungeon[r - 1][c - 1] + 1 : 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int rgt = solve(i, j + 1, dungeon, r, c, dp);
    int dwn = solve(i + 1, j, dungeon, r, c, dp);

    int mini = min(rgt, dwn) - dungeon[i][j];

    return dp[i][j] = mini <= 0 ? 1 : mini;
}
int calculateMinimumHP(vector<vector<int>> &dungeon)
{
    int r = dungeon.size();
    int c = dungeon[0].size();
    vector<vector<int>> dp(r, vector<int>(c, -1));
    return solve(0, 0, dungeon, r, c, dp);
}

int main()
{
    int x, y;
    cin >> x >> y;
    vector<vector<int>> grid(x, vector<int>(y));
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> grid[i][j];
        }
    }

    // Tabulation

    vector<vector<int>> dp(x, vector<int>(y, 0));

    for (int i = x - 1; i >= 0; i--)
    {
        for (int j = y-1; j >= 0; j--)
        {
            if (i == x - 1 && j == y - 1)
            {
                // base-case-intialization
                dp[x - 1][y - 1] = grid[x - 1][y - 1] > 0 ? 1 : -grid[x - 1][y - 1] + 1;
            }
            else
            {
                int rgt = 1e8;
                int dwn = 1e8;
                if (j < y - 1)
                    rgt = dp[i][j + 1];
                if (i < x - 1)
                    dwn = dp[i + 1][j];

                int mini = min(rgt, dwn) - grid[i][j];

                if (mini <= 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = mini;
            }
        }
    }

    cout << dp[0][0];

    // cout << calculateMinimumHP(grid);
    return 0;
}