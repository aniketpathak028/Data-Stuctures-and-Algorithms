

#include<bits/stdc++.h>

using namespace std;

// APPROACH #1 (RECURENCE) [T.C -> O(9^(m*n)), S.C -> O(m*n)+O(9^(m+n))]

// int solve(int r, int c, int i, int j1, int j2, vector<vector<int>> &grid)
// {
//     if (j1 < 0 || j1 > c - 1 || j2 < 0 || j2 > c - 1)
//         return -1e9;

//     if (i == r - 1)
//     {
//         if (j1 == j2)
//             return grid[i][j1];
//         else
//             return grid[i][j1] + grid[i][j2];
//     }

//     int maxi = 0;

//     for (int dj1 = -1; dj1 <= 1; dj1++)
//     {
//         for (int dj2 = -1; dj2 <= 1; dj2++)
//         {
//             if (j1 == j2)
//                 maxi = max(maxi, solve(r, c, i + 1, j1 + dj1, j2 + dj2, grid) + grid[i][j1]);
//             else
//                 maxi = max(maxi, solve(r, c, i + 1, j1 + dj1, j2 + dj2, grid) + grid[i][j1] + grid[i][j2]);
//         }
//     }

//     return maxi;
// }

// int maximumChocolates(int r, int c, vector<vector<int>> &grid)
// {
//     return solve(r, c, 0, 0, c - 1, grid);
// }

// APPROACH #2 (MEMOIZATION) [T.C -> O(m*n), S.C -> O(m*n)+O(9^(m+n))]

// int solve(int r, int c, int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
// {
//     if (j1 < 0 || j1 > c - 1 || j2 < 0 || j2 > c - 1)
//         return -1e9;

//     if (i == r - 1)
//     {
//         if (j1 == j2)
//             return grid[i][j1];
//         else
//             return grid[i][j1] + grid[i][j2];
//     }

//     if (dp[i][j1][j2] != -1)
//         return dp[i][j1][j2];

    // int maxi = 0;

    // for (int dj1 = -1; dj1 <= 1; dj1++)
    // {
    //     for (int dj2 = -1; dj2 <= 1; dj2++)
    //     {
    //         if (j1 == j2)
    //             maxi = max(maxi, solve(r, c, i + 1, j1 + dj1, j2 + dj2, grid, dp) + grid[i][j1]);
    //         else
    //             maxi = max(maxi, solve(r, c, i + 1, j1 + dj1, j2 + dj2, grid, dp) + grid[i][j1] + grid[i][j2]);
    //     }
    // }

//     return dp[i][j1][j2] = maxi;
// }

// int maximumChocolates(int r, int c, vector<vector<int>> &grid)
// {
//     vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
//     return solve(r, c, 0, 0, c - 1, grid, dp);
// }

// APPROACH #3 (TABULATION) [T.C -> O(9^(m*n)), S.C -> O(m*n)+O(9^(m+n))]

// int maximumChocolates(vector<vector<int>> &grid)
// {
//     int c = grid[0].size() - 1;
//     int r = grid.size() - 1;
//     vector<vector<vector<int>>> dp(r + 1, vector<vector<int>>(c + 1, vector<int>(c + 1, 0)));

//     // base-case intialization
//     for (int j1 = 0; j1 <= c; j1++)
//     {
//         for (int j2 = 0; j2 <= c; j2++)
//         {
//             if (j1 == j2)
//                 dp[r][j1][j2] = grid[r][j1];
//             else
//                 dp[r][j1][j2] = grid[r][j1] + grid[r][j2];
//         }
//     }

//     for (int i = r - 1; i >= 0; i--)
//     {
//         for (int j1 = 0; j1 <= c; j1++)
//         {
//             for (int j2 = 0; j2 <= c; j2++)
//             {
//                 int maxi = 0;
//                 for (int dj1 = -1; dj1 <= 1; dj1++)
//                 {
//                     for (int dj2 = -1; dj2 <= 1; dj2++)
//                     {
//                         if (j1 == j2)
//                         {
//                             if (j1 + dj1 >= 0 && j1 + dj1 <= c && j2 + dj2 >= 0 && j2 + dj2 <= c)
//                             {
//                                 maxi = max(maxi, dp[i + 1][j1 + dj1][j2 + dj2] + grid[i][j1]);
//                             }
//                         }
//                         else if (j1 + dj1 >= 0 && j1 + dj1 <= c && j2 + dj2 >= 0 && j2 + dj2 <= c)
//                             maxi = max(maxi, dp[i + 1][j1 + dj1][j2 + dj2] + grid[i][j1] + grid[i][j2]);
//                     }
//                 }
//                 dp[i][j1][j2] = maxi;
//             }
//         }
//     }

//     return dp[0][0][c];
// }

// APPROACH #4 (SPACE-OPTIMIZATION) [T.C -> O(9^(m*n)), S.C -> O(m*n)+O(9^(m+n))]

int maximumChocolates(vector<vector<int>> &grid)
{
    int c = grid[0].size() - 1;
    int r = grid.size() - 1;
    vector<vector<int>> prev(vector<vector<int>>(c + 1, vector<int>(c + 1, 0)));

    // base-case intialization
    for (int j1 = 0; j1 <= c; j1++)
    {
        for (int j2 = 0; j2 <= c; j2++)
        {
            if (j1 == j2)
                prev[j1][j2] = grid[r][j1];
            else
                prev[j1][j2] = grid[r][j1] + grid[r][j2];
        }
    }

    for (int i = r - 1; i >= 0; i--)
    {
        vector<vector<int>> curr(vector<vector<int>>(c + 1, vector<int>(c + 1, 0)));
        for (int j1 = 0; j1 <= c; j1++)
        {
            for (int j2 = 0; j2 <= c; j2++)
            {
                int maxi = 0;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        if (j1 == j2)
                        {
                            if (j1 + dj1 >= 0 && j1 + dj1 <= c && j2 + dj2 >= 0 && j2 + dj2 <= c)
                            {
                                maxi = max(maxi, prev[j1 + dj1][j2 + dj2] + grid[i][j1]);
                            }
                        }
                        else if (j1 + dj1 >= 0 && j1 + dj1 <= c && j2 + dj2 >= 0 && j2 + dj2 <= c)
                            maxi = max(maxi, prev[j1 + dj1][j2 + dj2] + grid[i][j1] + grid[i][j2]);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        prev = curr;
    }

    return prev[0][c];
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    cout<<maximumChocolates(grid);
    return 0;
}