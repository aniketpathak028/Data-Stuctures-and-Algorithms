#include <bits/stdc++.h>
using namespace std;

// recurrence (T.C= exponential)

// int solve(int i, int j, vector<int> &mat){
//     // base-case
//     if(i==j)
//         return 0;

//     int mini = INT_MAX;

//     // iterate for all partitions
//     for (int k = i; k < j; ++k){
//         // total_cost= cost(multiplying the two partitions) + cost(each partition separately)
//         int step_count = mat[i - 1] * mat[k] * mat[j] + solve(i, k, mat) + solve(k + 1, j, mat);
//         mini = min(mini, step_count);
//     }

//     return mini;
// }

// int main()
// {
//     vector<int> mat = {10, 20, 30, 40, 50};
//     cout << solve(1, mat.size()-1, mat);
//     return 0;
// }

// memoization (T.C = O(n^3) , S.C = O(n^2) + O(n)--> Auxiliary Stack Space)

// int solve(int i, int j, vector<int> &mat, vector<vector<int>> &dp)
// {
//     // base-case
//     if (i == j)
//         return 0;

//     if(dp[i][j]!=-1)
//         return dp[i][j];

//     int mini = INT_MAX;

//     // iterate for all partitions
//     for (int k = i; k < j; ++k)
//     {
//         // total_cost= cost(multiplying the two partitions) + cost(each partition separately)
//         int step_count = mat[i - 1] * mat[k] * mat[j] + solve(i, k, mat, dp) + solve(k + 1, j, mat, dp);
//         mini = min(mini, step_count);
//     }

//     return dp[i][j]= mini;
// }

// int main()
// {
//     vector<int> mat = {10, 20, 30, 40, 50};
//     int n = mat.size();
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     cout << solve(1, n - 1, mat, dp);
//     return 0;
// }

// tabulation (T.C = O(n^3) , S.C = O(n^2))

int main()
{
    vector<int> mat = {10, 20, 30, 40, 50};

    int n = mat.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // base-case
    for (int i = 0; i < n; ++i)
        dp[i][i] = 0;

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int mini = INT_MAX;

            // iterate for all partitions
            for (int k = i; k < j; ++k)
            {
                // total_cost= cost(multiplying the two partitions) + cost(each partition separately)
                int step_count = mat[i - 1] * mat[k] * mat[j] + dp[i][k] + dp[k + 1][j];
                mini = min(mini, step_count);
            }

            dp[i][j] = mini;
        }
    }

    cout << dp[1][n - 1];
    return 0;
}