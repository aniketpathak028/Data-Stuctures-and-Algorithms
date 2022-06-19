#include<bits/stdc++.h>

using namespace std;

int allPalindromes(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i] == s2[j])
                dp[i][j] = 2 + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j]+dp[i][j - 1];
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
    cout << allPalindromes(s1, s2);
    return 0;
}