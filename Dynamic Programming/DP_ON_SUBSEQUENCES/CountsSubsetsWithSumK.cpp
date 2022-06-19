// Link: https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include<bits/stdc++.h>

using namespace std;

// Recurrence [T.C = O(2^N), S.C = O(N)]
// int solve(int i, int tar, vector<int> &num)
// {
//     // base-case
//     if (tar == 0)
//         return 1;
//     if (i < 0)
//         return 0;

//     int pick, not_pick;
//     pick = not_pick = 0;
//     // pick
//     if (tar >= num[i])
//         pick = solve(i - 1, tar - num[i], num);
//     // not pick
//     not_pick = solve(i - 1, tar, num);

//     return pick + not_pick;
// }

// int findWays(vector<int> &num, int tar)
// {
//     return solve(num.size() - 1, tar, num);
// }

// Memoization [T.C = O(N*tar), S.C = O(N)+O(N*tar)]
// int solve(int i, int tar, vector<int> &num, vector<vector<int>> &dp)
// {
//     // base-case
//     if (tar == 0)
//         return 1;
//     if (i < 0)
//         return 0;

//     if (dp[i][tar] != -1)
//         return dp[i][tar];

//     int pick, not_pick;
//     pick = not_pick = 0;
//     // pick
//     if (tar >= num[i])
//         pick = solve(i - 1, tar - num[i], num, dp);
//     // not pick
//     not_pick = solve(i - 1, tar, num, dp);

//     return dp[i][tar] = pick + not_pick;
// }

// int findWays(vector<int> &num, int tar)
// {
//     int n = num.size();
//     vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
//     return solve(n - 1, tar, num, dp);
// }

// Tabulation [T.C = O(N*tar), S.C = O(N*tar)]
// int findWays(vector<int> &num, int tar)
// {
//     int n = num.size();
//     // intialize-dp
//     vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
//     // base-case intialization
//     for (int i = 0; i < n; i++)
//         dp[i][0] = 1;
//     if (num[0] <= tar)
//         dp[0][num[0]] = 1;
//     // tabulation
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 1; j <= tar; j++)
//         {
//             int pick, not_pick;
//             pick = not_pick = 0;
//             // pick
//             if (j >= num[i])
//                 pick = dp[i - 1][j - num[i]];
//             // not pick
//             not_pick = dp[i - 1][j];

//             dp[i][j] = pick + not_pick;
//         }
//     }
//     return dp[n - 1][tar];
// }

// Space-Optimization [T.C = O(N*tar), S.C = O(tar)]
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    // intialize-dp
    vector<int> prev(tar + 1, 0);
    vector<int> curr(tar + 1, 0);
    // base-case intialization
    prev[0] = curr[0] = 1;
    if (num[0] <= tar)
        prev[num[0]] = 1;
    // tabulation
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= tar; j++)
        {
            int pick, not_pick;
            pick = not_pick = 0;
            // pick
            if (j >= num[i])
                pick = prev[j - num[i]];
            // not pick
            not_pick = prev[j];

            curr[j] = pick + not_pick;
        }
        prev = curr;
    }
    return prev[tar];
}