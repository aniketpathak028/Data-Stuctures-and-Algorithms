// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>

using namespace std;

// ***************memoization - dp***************
int frogJump(int n, vector<int> &heights, vector<int> &dp, int k)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = INT_MAX;
    for (int i = 1; i<=k; i++){
        if(n>=i){
            if(frogJump(n-i, heights, dp, k)+ abs(heights[n]-heights[n-i])<dp[n])
                dp[n] = frogJump(n - i, heights, dp, k) + abs(heights[n] - heights[n - i]);
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> heights;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        heights.push_back(num);
    }

    // vector<int> dp(n + 1, -1); // n+1 sized vector to have nth index
    // cout << endl<<frogJump(n-1, heights, dp, k);


    // Tabulation - DP
    vector<int> dp(n); //initializing dp vector
    dp[0] = 0;
    for (int i = 1; i < n; i++){       // T.C = O(N*k)
        int min_steps = INT_MAX;
        for (int j = 1; j <= k; j++){
            if(i>=j){
                min_steps = min(min_steps, dp[i - j]+abs(heights[i]-heights[i-j]));
            }
        }
        dp[i] = min_steps;
    }

    cout<< dp[n - 1];

    return 0;
}