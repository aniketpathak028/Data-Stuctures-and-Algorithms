#include<bits/stdc++.h>
using namespace std;

int isSubsetSum(int N, int arr[])
{
    int tot_sum = 0;
    for (int i = 0; i < N; i++)
        tot_sum += arr[i];

    int sum = tot_sum;
    vector<vector<bool>> dp(N, vector<bool>(sum + 1, false));
    // base case intialization
    for (int i = 0; i < N; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    int mini = INT_MAX;

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            bool not_pick = dp[i - 1][j];
            bool pick = false;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];

            dp[i][j] = pick | not_pick;
        }
    }

    for (int i = 0; i <= sum; i++){
        if(dp[N-1][i]) {
                mini = min(mini, abs((tot_sum - i) - i));
        }
    }

    return mini;
}

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << isSubsetSum(N, arr);
    return 0;
}