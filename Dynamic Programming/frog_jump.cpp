// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>

using namespace std;

// *************** recursion - recurrence ***************
// int frogJump(int n, vector<int> &heights)
// {
//     if (n <= 1)
//         return 0;

//     int One_Jump = abs(heights[n - 1] - heights[n - 2]) + frogJump(n - 1, heights);
//     if (n >= 3)
//     {
//         int Two_Jump = abs(heights[n - 1] - heights[n - 3]) + frogJump(n - 2, heights);
//         return min(One_Jump, Two_Jump);
//     }
//     return One_Jump;
// }

// *************** memoization - dp ***************
// int frogJump(int n, vector<int> &heights, vector<int> &dp)
// {
//     if (n <= 1)
//         return 0;

//     if (dp[n] != -1)
//         return dp[n];
//     int One_Jump = abs(heights[n - 1] - heights[n - 2]) + frogJump(n - 1, heights, dp);
//     if (n >= 3)
//     {
//         int Two_Jump = abs(heights[n - 1] - heights[n - 3]) + frogJump(n - 2, heights, dp);
//         return dp[n] = min(One_Jump, Two_Jump);
//     }
//     return dp[n] = One_Jump;
// }

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> heights;
    cout << "Enter heights: " << endl;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        heights.push_back(num);
    }

    // cout << endl
    //      << "The minimum energy required is: " << frogJump(n, heights);

    // vector<int> dp(n + 1, -1); // n+1 sized vector to have nth index
    // cout << endl
    //      << "The minimum energy required is: " << frogJump(n, heights, dp);

    // **************** TABULATION ****************
    vector<int> dp(n, -1); // initializing n sized dp 0 indexed
    dp[0] = 0; // initializing base case
    for (int i = 1; i <= n - 1; i++){
        int l = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int r = INT_MAX;
        if(i>1){
            r = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(l, r);
    }
    cout << dp[n - 1];
    return 0;

    // ********** SPACE OPTIMIZATION **********
    // int prev = 0;
    // int prev2 = 0;
    // for (int i = 1; i <= n - 1; i++)
    // {
    //     int l = prev + abs(heights[i] - heights[i - 1]);
    //     int r = INT_MAX;
    //     if (i > 1)
    //     {
    //         r = prev2 + abs(heights[i] - heights[i - 2]);
    //     }
    //     int curr = min(l, r);
    //     prev2 = prev;
    //     prev = curr;
    // }
    // return prev;
}