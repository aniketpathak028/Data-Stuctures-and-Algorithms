#include<bits/stdc++.h>

using namespace std;

// DP (Memoization) [T.C = O(n*n) , S.C = O(n^2)+O(n)]

// int solve(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
// {
//     // out-of-bound condition
//     if (j < 0 || j >= n)
//         return 1e8;

//     // base case
//     if (i == n - 1)
//         return matrix[i][j];

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int mini = INT_MAX;
//     for (int dj = -1; dj <= 1; dj++)
//     {
//         mini = min(mini, solve(i + 1, j + dj, n, matrix, dp) + matrix[i][j]);
//     }

//     return dp[i][j] = mini;
// }

// int minFallingPathSum(vector<vector<int>> &matrix)
// {
//     int mini = INT_MAX;
//     int n = matrix.size();
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     for (int i = 0; i < n; i++)
//     {
//         mini = min(mini, solve(0, i, n, matrix, dp));
//     }

//     return mini;
// }

// Tabulation [T.C = O(n*n) , S.C = O(n*n)]

// int minFallingPathSum(vector<vector<int>> &matrix)
// {
//     int mini = INT_MAX;
//     int n = matrix.size();

//     // initialize DP
//     vector<vector<int>> dp(n, vector<int>(n, 0));

//     // base-case initialization
//     for (int i = 0; i < n; i++)
//     {
//         dp[n-1][i]= matrix[n-1][i];
//     }

//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 0; j < n; j++){
//             int mini = INT_MAX;
//             for (int dj = -1; dj <= 1; dj++)
//             {
//                 mini = min(mini, dp[i + 1][j + dj] + matrix[i][j]);
//             }

//             dp[i][j] = mini;
//         }
//     }

//     int mini = INT_MAX;

//     for (int i = 0; i < n; i++)
//     {
//         mini = min(mini, dp[0][i]);
//     }

//     return mini;
// }

// Space-Optimiation [T.C = O(n*n) , S.C = O(n)]

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int mini = INT_MAX;
    int n = matrix.size();

    // initialize DP
    vector<int> prev(n, 0);

    // base-case initialization
    for (int i = 0; i < n; i++)
    {
        prev[i] = matrix[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            int mini = INT_MAX;
            for (int dj = -1; dj <= 1; dj++)
            {
                if (j + dj < n && j + dj >= 0)
                    mini = min(mini, prev[j + dj] + matrix[i][j]);
            }

            curr[j] = mini;
        }
        prev = curr;
    }

    for (int i = 0; i < n; i++)
    {
        mini = min(mini, prev[i]);
    }

    return mini;
}

int main()
{
    return 0;
}