#include<bits/stdc++.h>

using namespace std;

// MEMOIZATION

// int solve(vector<vector<int>> &triangle, int i, int j, int n, vector<vector<int>> &dp)
// {
//     if (i == n-1)
//         return triangle[i][j];

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int d, dr;
//     d = triangle[i][j] + solve(triangle, i + 1, j, n, dp);
//     dr = triangle[i][j] + solve(triangle, i + 1, j + 1, n, dp);

//     return dp[i][j] = min(d, dr);
// }

// int minimumPathSum(vector<vector<int>> &triangle, int n)
// {
//     vector<vector<int>> dp(n);
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> row(i + 1, -1);
//         dp[i] = row;
//     }
//     return solve(triangle, 0, 0, n, dp);
// }

// TABULATION

// int minimumPathSum(vector<vector<int>> &triangle, int n)
// {
//     vector<vector<int>> dp(n);
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> row(i + 1, -1);
//         dp[i] = row;
//     }
//     for (int i = 0; i < n; i++){
//         dp[n - 1][i] = triangle[n - 1][i];
//     }
//         for (int i = n-2; i >= 0; i--)
//         {
//             for (int j = i; j >= 0; j--)
//             {
//                 int d, dr;
//                 d = triangle[i][j] + dp[i+1][j];
//                 dr = triangle[i][j] + dp[i][j+1];

//                 dp[i][j] = min(d, dr);
//             }
//         }

//         return dp[0][0];
// }

// SPACE-OPTIMIZATION

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> prev(n);
    for (int i = 0; i < n; i++)
    {
        prev[i] = triangle[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> curr(i + 1);
        for (int j = i; j >= 0; j--)
        {
            int d, dr;
            d = triangle[i][j] + prev[j];
            dr = triangle[i][j] + prev[j + 1];

            curr[j] = min(d, dr);
        }
        prev = curr;
    }

    return prev[0];
}

int main()
{

    int n;
    cin >> n;
    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++){
        vector<int> row(i + 1);
        for (int j = 0; j <= i; j++){
            cin >> row[j];
        }
        grid[i] = row;
    }
    cout << minimumTotal(grid);
    return 0;
}