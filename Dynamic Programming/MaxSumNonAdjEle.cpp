#include<bits/stdc++.h>

using namespace std;

// recursive approach

// int solve(vector<int> &nums, int n)
// {
//     if (n <= -1)
//         return 0;

//     int l = nums[n] + solve(nums, n - 2);

//     int r = solve(nums, n - 1);

//     return max(l, r);
// }
// int maximumNonAdjacentSum(vector<int> &nums)
// {
//     int size = nums.size();
//     return solve(nums, size - 1);
// }

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // tabulation-method

    // vector<int> dp(n, -1);
    // dp[0] = a[0]; // base case initialization
    // for (int i = 1; i < n; i++){
    //     int take = a[i];
    //     if(i>1)
    //         take += dp[i - 2];
    //     int not_take = dp[i - 1];
    //     dp[i] = max(take, not_take);
    // }
    // cout << dp[n - 1];

    int prev = a[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int take = a[i];
        if (i > 1)
            take += prev2;
        int not_take = prev;
        int curr = max(take, not_take);
        prev2 = prev;
        prev = curr;
    }
    cout << prev;
    return 0;
}


// memoization-dp

// int solve(vector<int> &nums, int n, vector<int> &dp)
// {
//     if (n <= -1)
//         return 0;

//     if (dp[n] != -1)
//         return dp[n];

//     int l = nums[n] + solve(nums, n - 2, dp);

//     int r = solve(nums, n - 1, dp);

//     return dp[n] = max(l, r);
// }
// int maximumNonAdjacentSum(vector<int> &nums)
// {
//     int size = nums.size();
//     vector<int> dp(size, -1);
//     solve(nums, size - 1, dp);
//     return dp[size - 1];
// }

