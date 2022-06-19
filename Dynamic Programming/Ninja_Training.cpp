// P.S -> https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

// # Approach-1 (RECURSION)  -> T.C.=O(2^n), S.C.=O(n) + O(n)

// #include<bits/stdc++.h>

// using namespace std;

// int maxPoints(int day, int last, vector<vector<int>> &points)
// {
//     if (day == 0)
//     {
//         int maxi = 0;
//         for (int i = 0; i < 3; i++)
//         {
//             if (i != last)
//             {
//                 maxi = max(maxi, points[0][i]);
//             }
//         }
//         return maxi;
//     }

//     int maxi = 0;
//     for (int i = 0; i < 3; i++)
//     {
//         if (i != last)
//         {
//             int point = points[day][i] + maxPoints(day - 1, i, points);
//             maxi = max(maxi, point);
//         }
//     }

//     return maxi;
// }

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     return maxPoints(n - 1, 3, points);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> a(n, vector<int> (3, 0));
    
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < 3; j++){
//             int x;
//             cin >> x;
//             a[i][j]= x;
//         }
//     }
//     cout << ninjaTraining(n, a);
//     return 0;
// }

// # Approach-2 (MEMOIZATION-DP) -> T.C.=O(12*n), S.C.=O(n*4) + O(n)

// #include <bits/stdc++.h>

// using namespace std;

// int maxPoints(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
// {
//     if (day == 0)
//     {
//         int maxi = 0;
//         for (int i = 0; i < 3; i++)
//         {
//             if (i != last)
//             {
//                 maxi = max(maxi, points[0][i]);
//             }
//         }
//         return maxi;
//     }

//     if (dp[day][last] != -1)
//         return dp[day][last];

//     int maxi = 0;
//     for (int i = 0; i < 3; i++)
//     {
//         if (i != last)
//         {
//             int point = points[day][i] + maxPoints(day - 1, i, points, dp);
//             maxi = max(maxi, point);
//         }
//     }

//     return dp[day][last] = maxi;
// }

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector<vector<int>> dp(n, vector<int>(4, -1));
//     return maxPoints(n - 1, 3, points, dp);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> a(n, vector<int>(3, 0));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             int x;
//             cin >> x;
//             a[i][j] = x;
//         }
//     }
//     cout << ninjaTraining(n, a);
//     return 0;
// }

// # Approach - 3 (TABULATION) -> T.C.=O(12*n), S.C.=O(n*4)

// #include <bits/stdc++.h>

// using namespace std;

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector<vector<int>> dp(n, vector<int>(4, -1)); 

//     // initialization-base conditions
//     dp[0][0] = max(points[0][2], points[0][1]);
//     dp[0][1] = max(points[0][2], points[0][0]);
//     dp[0][2] = max(points[0][1], points[0][0]);
//     dp[0][3] = max(points[0][2], max(points[0][1], points[0][0]));

//     for (int day = 1; day < n; day++){
//         for (int last = 0; last < 4; last++)
//         {
//             dp[day][last] = 0;
//             for (int task = 0; task < 3; task++) {
//                 if(task!=last)
//                     dp[day][last] = max(dp[day][last], dp[day - 1][task] + points[day][task]);
//             }
//         }
//     }

//         return dp[n-1][3];
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> a(n, vector<int>(3, 0));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             int x;
//             cin >> x;
//             a[i][j] = x;
//         }
//     }
//     cout << ninjaTraining(n, a);
//     return 0;
// }

// # Approach - 4 (SPACE OPTIMIZATION) -> T.C.=O(12*n), S.C.=O(4)

#include <bits/stdc++.h>

using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);

    // initialization-base conditions
    prev[0] = max(points[0][2], points[0][1]);
    prev[1] = max(points[0][2], points[0][0]);
    prev[2] = max(points[0][1], points[0][0]);
    prev[3] = max(points[0][2], max(points[0][1], points[0][0]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                    temp[last] = max(temp[last], prev[task] + points[day][task]);
            }
        }
    }

    return prev[3];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            a[i][j] = x;
        }
    }
    cout << ninjaTraining(n, a);
    return 0;
}