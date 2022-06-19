#include<bits/stdc++.h>

using namespace std;

int mod = (int)1e9 + 7;
int countPartitions(int n, int d, vector<int> &arr)
{
    int sum = 0;
    for (auto i : arr)
        sum += i;
    if (sum - d < 0 | (sum - d) % 2)
        return 0;
    int tar = (sum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    // base-case
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (arr[0] != 0 && arr[0] <= tar)
        dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            int pick, not_pick;
            pick = not_pick = 0;
            // pick
            if (j >= arr[i])
                pick = dp[i - 1][j - arr[i]];
            // not pick
            not_pick = dp[i - 1][j];
            dp[i][j] = (pick + not_pick) % mod;
        }
    }
    return dp[n - 1][tar];
}
int main()
{
    return 0;
}