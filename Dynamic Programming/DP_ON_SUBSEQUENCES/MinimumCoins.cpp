#include<bits/stdc++.h>

using namespace std;

// Memoized solution [T.C = O(N*target), S.C = O(N*target)+O(target)]
int solve(int i, int sum, vector<int> &num, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (sum % num[0] == 0)
            return sum / num[0];
        else
            return 1e9;
    }

    if (dp[i][sum] != -1)
        return dp[i][sum];

    int pick, not_pick;
    pick = INT_MAX;
    not_pick = solve(i - 1, sum, num, dp);
    if (num[i] <= sum)
        pick = 1 + solve(i, sum - num[i], num, dp);

    return dp[i][sum] = min(pick, not_pick);
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int ans = solve(n - 1, x, num, dp);
    if (ans >= 1e9)
        return -1;
    else
        return ans;
}

// Tabulation
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    // base-case
    for (int i = 0; i <= x; i++)
    {
        if (i % num[0] == 0)
            dp[0][i] = i / num[0];
        else
            dp[0][i] = 1e9;
    }
    // tabulation
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            int pick, not_pick;
            pick = INT_MAX;
            not_pick = dp[i - 1][j];
            if (num[i] <= j)
                pick = 1 + dp[i][j - num[i]];
            dp[i][j] = min(pick, not_pick);
        }
    }
    int ans = dp[n - 1][x];
    if (ans >= 1e9)
        return -1;
    else
        return ans;
}

// Space-Optimization
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<int> prev(x + 1, -1), curr(x + 1, -1);
    // base-case
    for (int i = 0; i <= x; i++)
    {
        if (i % num[0] == 0)
            prev[i] = i / num[0];
        else
            prev[i] = 1e9;
    }
    // tabulation
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            int pick, not_pick;
            pick = INT_MAX;
            not_pick = prev[j];
            if (num[i] <= j)
                pick = 1 + curr[j - num[i]];
            curr[j] = min(pick, not_pick);
        }
        prev = curr;
    }
    int ans = prev[x];
    if (ans >= 1e9)
        return -1;
    else
        return ans;
}

int main()
{
    return 0;
}