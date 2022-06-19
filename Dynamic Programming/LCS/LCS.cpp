// Longest common subsequence problem
#include <bits/stdc++.h>

using namespace std;

// MEMOIZATION [T.C=O(i*j), S.C=O(i)+O(i*j)]
// int lcs(int i, int j, string s1, string s2, vector<vector<int>> &dp)
// {
//     // base-case
//     if (i < 0 | j < 0)
//         return 0;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     if (s1[i] == s2[j])
//         return dp[i][j] = 1+lcs(i - 1, j - 1, s1, s2, dp);

//     return dp[i][j] = max(lcs(i - 1, j, s1, s2, dp), lcs(i, j - 1, s1, s2, dp));
// }

// TABULATION [T.C=O(i*j), S.C=O(i)+O(i*j)]
int lcs(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for (int i = 1; i <= n1; i++){
        for (int j = 1; j <= n2; j++){
            if (s1[i] == s2[j])
               dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n1][n2];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int i = s1.size();
    int j = s2.size();
    vector<vector<int>> dp(i, vector<int>(j, -1));
    // cout<< lcs(i - 1, j - 1, s1, s2, dp);
    cout << lcs(s1, s2);
    return 0;
}