#include <bits/stdc++.h>

using namespace std;

// memoized code
// int fun(int n, vector<int> &dp)
// {
//     if (n <= 1)
//         return 1;

//     if (dp[n] != -1)
//         return dp[n];
//     return dp[n] = fun(n - 1, dp) + fun(n - 2, dp);
// }

int main()
{
    int n;
    cout << "Enter n: " << endl;
    cin >> n;
    vector<int> dp(n + 1, -1);
    // cout << endl << fun(n, dp);


    // ***** Tabulation method ******
    // dp[1] = 1; // base case initialization

    // for (int i = 2; i <= n; i++)
    // {
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }

    int curr, prev1, prev2;
    for (int i = 2; i <= n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

        cout << prev1;
    return 0;
}