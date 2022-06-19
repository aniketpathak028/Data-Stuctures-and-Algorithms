// P.S : https: // www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// # APPROACH-1 (RECURSION) [T.C. => O(2^(M*N)), S.C => O(M+N)O(M+N) + O(M*N)]
// #include<bits/stdc++.h>

// using namespace std;

// int totalPaths(int row, int col)
// {
//     // Base-Case
//     if(row==0 && col==0)
//         return 1;
//     if(row<0 || col<0)
//         return 0;

//     int up = totalPaths(row - 1, col);
//     int left = totalPaths(row, col - 1);

//     return up + left;
// }

// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     cout<<totalPaths(m-1, n-1);
//     return 0;
// }

// # APPROACH-2 (MEMOIZATION) [T.C. => O(M*N), S.C => O(M+N) + O(M*N)]

// #include <bits/stdc++.h>

// using namespace std;

// int totalPaths(int row, int col, vector<vector<int>> dp)
// {
//     // Base-Case
//     if (row == 0 && col == 0)
//         return 1;
//     if (row < 0 || col < 0)
//         return 0;

//     if (dp[row][col] != -1)
//         return dp[row][col];

//     int up = totalPaths(row - 1, col, dp);
//     int left = totalPaths(row, col - 1, dp);

//     return dp[row][col] = up + left;
// }

// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     vector<vector<int>> dp(m, vector<int>(n, -1));
//     cout << totalPaths(m - 1, n - 1, dp);
//     return 0;
// }

// # APPROACH-3 (TABULATION) [T.C. => O(M*N), S.C => O(M+N)]

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     vector<vector<int>> dp(m, vector<int>(n, -1));
    
//     for (int i = 0; i < m; i++){
//         for (int j = 0; j < n; j++) {
//             if (i == 0 && j == 0) // base case initialization
//                 dp[i][j] = 1;
            
//             else{
//                 int up = 0;
//                 int left = 0;

//                 // avoid neg(-ve) indices
//                 if (i > 0)
//                     up = dp[i - 1][j];
//                 if (j > 0)
//                     left = dp[i][j - 1];

//                 dp[i][j] = up + left;
//             }
          
//         }
//     }

//     cout << dp[m - 1][n - 1];

//     return 0;
// }

// # APPROACH-4 (SPACE-OPTIMIZATION) [T.C. => O(M*N), S.C => O(N)]

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0) // base case initialization
                curr[j] = 1;

            else
            {
                int up = 0;
                int left = 0;

                // avoid neg(-ve) indices
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];

                curr[j] = up + left;
            }
        }
        prev = curr;
    }

    cout << prev[n - 1];

    return 0;
}