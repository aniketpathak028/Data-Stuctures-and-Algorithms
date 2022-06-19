// SUBSET SUM PROBLEM
// http://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#

#include<bits/stdc++.h>

using namespace std;

// Memoization [T.C = O(Sum*N), S.C=O(N)+O(N*Sum)]
// bool solve(int i, int target, int arr[], vector<vector<int>> &dp)
// {
//     if (target == 0)
//         return true;
//     if (i == 0)
//         return arr[i] == target;

//     if(dp[i][target]!=-1)
//         return dp[i][target];

    // bool not_pick = solve(i - 1, target, arr, dp);
    // bool pick = false;
    // if (arr[i] <= target)
    //     pick = solve(i - 1, target - arr[i], arr, dp);

    // return dp[i][target] = pick || not_pick;
// }
// bool isSubsetSum(int N, int arr[], int sum)
// {
//     vector<vector<int>> dp(N, vector<int>(sum + 1, -1));
//     return solve(N - 1, sum, arr, dp);
// }

// Tabulation [T.C = O(Sum*N), S.C=O(N)+O(N*Sum)]
bool isSubsetSum(int N, int arr[], int sum)
{
    vector<vector<bool>> dp(N, vector<bool>(sum + 1, false));
    // base case intialization
    for (int i = 0; i < N; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    for (int i = 1; i < N; i++){
        for (int j = 0; j <=sum; j++){
            bool not_pick = dp[i - 1][j];
            bool pick = false;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];

            dp[i][j] = pick || not_pick;
        }
    }

    return dp[N - 1][sum];
}

// Space-Optimization [T.C = O(Sum*N), S.C=O(N)+O(N*Sum)]
bool isSubsetSum(int N, int arr[], int sum)
{
    vector<vector<bool>> dp(N, vector<bool>(sum + 1, false));
    // base case intialization
    for (int i = 0; i < N; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            bool not_pick = dp[i - 1][j];
            bool pick = false;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];

            dp[i][j] = pick || not_pick;
        }
    }

    return dp[N - 1][sum];
}

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << isSubsetSum(N, arr, 5);
    return 0;
}