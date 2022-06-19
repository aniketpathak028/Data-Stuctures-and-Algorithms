#include<bits/stdc++.h>
using namespace std;

// APPROACH #1 (RECURSION) [T.C = O(2^(M*N)), S.C = O(m+n-2) + O(m*n)]

// int minSum(vector<vector<int>> &grid, int i, int j)
// {
//     if (i == 0 && j == 0)
//         return grid[0][0];

//     if (i < 0 || j < 0)
//         return 1e9;

//     int up, left;

//     up = grid[i][j] + minSum(grid, i - 1, j);

//     left = grid[i][j] + minSum(grid, i, j - 1);

//     return min(up, left);
// }

// int minSumPath(vector<vector<int>> &grid)
// {
//     int m = grid.size();
//     int n = grid[0].size();
//     return minSum(grid, m - 1, n - 1);
// }

// APPROACH #2 (MEMOIZATION) [T.C= O(m*n), S.C= O(m+n-2)+ O(m*n)]

// int minSum(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
// {
//     if (i == 0 && j == 0)
//         return grid[0][0];

//     if (i < 0 || j < 0)
//         return 1e9;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int up, left;

//     up = grid[i][j] + minSum(grid, i - 1, j, dp);

//     left = grid[i][j] + minSum(grid, i, j - 1, dp);

//     return dp[i][j] = min(up, left);
// }

// int minSumPath(vector<vector<int>> &grid)
// {
//     int m = grid.size();
//     int n = grid[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, -1));
//     return minSum(grid, m - 1, n - 1, dp);
// }

// APPROACH #3 (TABULATION) [T.C= O(m*n), S.C= O(m*n)]

// int minPathSum(vector<vector<int>> &grid)
// {
//     int m = grid.size();
//     int n = grid[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, -1));
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i == 0 && j == 0)
//                 dp[i][j] = grid[0][0];
//             else
//             {
//                 int up = grid[i][j];
//                 if (i > 0)
//                     up += dp[i - 1][j];
//                 else
//                     up += 1e9;

//                 int left = grid[i][j];
//                 if (j > 0)
//                     left += dp[i][j - 1];
//                 else
//                     left += 1e9;

//                 dp[i][j] = min(left, up);
//             }
//         }
//     }
//     return dp[m - 1][n - 1];
// }

// APPROACH #4 (SPACE-OPTIMIZATION) [T.C = O(m*n), S.C= O(n)]

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = grid[0][0];
            else
            {
                int up = grid[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up += 1e9;

                int left = grid[i][j];
                if (j > 0)
                    left += curr[j - 1];
                else
                    left += 1e9;

                curr[j] = min(left, up);
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}

int main()
{
    int x, y;
    cin >> x >> y;
    vector<vector<int>> grid(x, vector<int> (y));
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++)
        {
            cin >> grid[i][j];
        }
    }
    // cout<<endl<<minSumPath(grid);
    return 0;
}