#include<bits/stdc++.h>
using namespace std;

int findMax(int i, int j, int n, vector<vector<char>> &b, vector<vector<int>> &dp)
{
    if(i<0 | j<0 | i>n-1 | j>n-1)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int maxi = max(max(findMax(i - 1, j + 2, n, b, dp), findMax(i - 2, j + 1, n, b, dp)), max(findMax(i + 1, j + 2, n, b, dp), findMax(i + 2, j + 1, n, b, dp)));
    
    if(b[i][j]=='P')
        return dp[i][j]=maxi + 1;
    else
        return dp[i][j] = maxi;
}

int solve(vector<vector<char>> &b)
{
    int ki, kj;
    int n = b.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(b[i][j]=='K') {
                ki = i;
                kj = j;
                break;
            }
        }
    }
    return findMax(ki, kj, n, b, dp);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<char>> b(n, vector<char>(n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> b[i][j];
            }
        }
        int ans = solve(b);
        cout << ans << endl;
    }
    return 0;
}