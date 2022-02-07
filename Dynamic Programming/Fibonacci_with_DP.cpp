
#include <bits/stdc++.h>

using namespace std;

// ****Normal Recursion******
// int fun(int n){
//     if(n<=1) return n;
// O(2^n) -> T.C. && O(n) ->S.C.
//     return fun(n-1) + fun(n-2);
// }

// ****Memoization******
// int fun(int n, vector<int> &dp){
//     if(n<=1) return n;
// O(n) -> T.C. && O(n) ->S.C.
//     if(dp[n]!=-1) return dp[n];
//     return dp[n] = fun(n-1, dp) + fun(n-2, dp);
// }

int main()
{
    cout << "Enter n: " << endl;
    int n;
    cin >> n;

    // vector<int> dp(n+1, -1);

    // cout<<endl<<fun(n, dp);

    // ****Tabulation******
    // dp[0] = 0;
    // dp[1] = 1;
    // for(int i=2; i<=n; i++){
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    // cout<<dp[n];

    // ****Space Optimization******
    int prev1, prev2, curr;
    prev1= 1; prev2= 0;
    for(int i=2; i<=n; i++){
        curr = prev1+prev2;
        prev2= prev1;
        prev1= curr;
    }
    cout<< prev1;
    return 0;
}
