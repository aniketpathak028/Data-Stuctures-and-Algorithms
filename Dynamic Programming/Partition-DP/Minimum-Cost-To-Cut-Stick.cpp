#include <bits/stdc++.h>
using namespace std;

// P.S --> Given a stick of size n, and a cuts array consisting of lengths where the stick could be cut, find out
// minimum cost to cut the stick, if the cost to cut the stick is the length of the stick at that moment.

// recurrence (T.C = exponential)

// int findMinCost(int i, int j, vector<int> &cuts){
//     // base-case (if i exceeds j, the cost should be 0)
//     if(i>j)
//         return 0;

//     int mini = INT_MAX;
//     for (int k = i; k <= j; ++k)
//         length of stick= cuts[j+1]-cuts[i-1] which is the cost to cut the stick
//         the remaining subproblems can be solved independently because the array is sorted
//         mini = min(mini, cuts[j + 1] - cuts[i - 1] + findMinCost(i, k - 1, cuts) + findMinCost(k + 1, j, cuts));

//     return mini;
// }

// int main()
// {
//     vector<int> cuts = {3, 5, 1, 4};
//     // sort the cuts array and insert 0 at the beginning and the size of the stick at the end
    
//     cuts.insert(cuts.begin(), 0);
//     cuts.push_back(7);
//     sort(cuts.begin(), cuts.end());

//     // {0, 1, 3, 4, 5, 7}

//     cout << findMinCost(1, cuts.size()-2, cuts);
//     return 0;
// }

// memoization (T.C = O(n^3) , S.C = O(n^2) + Auxiliary Stack Space)

// int findMinCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
// {
//     // base-case (if i exceeds j, the cost should be 0)
//     if (i > j)
//         return 0;

//     if(dp[i][j]!=-1)
//         return dp[i][j];

//     int mini = INT_MAX;
//     for (int k = i; k <= j; ++k)
//         mini = min(mini, cuts[j + 1] - cuts[i - 1] + findMinCost(i, k - 1, cuts, dp) + findMinCost(k + 1, j, cuts, dp));

//     return dp[i][j]= mini;
// }

// int main()
// {
//     vector<int> cuts = {3, 5, 1, 4};
//     // sort the cuts array and insert 0 at the beginning and the size of the stick at the end

//     cuts.insert(cuts.begin(), 0);
//     cuts.push_back(7);
//     sort(cuts.begin(), cuts.end());

//     // {0, 1, 3, 4, 5, 7}

//     int n = cuts.size();

//     vector<vector<int>> dp(n, vector<int>(n, -1));

//     cout << findMinCost(1, cuts.size() - 2, cuts, dp);
//     return 0;
// }

// tabulation (T.C = O(n^3), S.C = O(n^2))

int main()
{
    vector<int> cuts = {3, 5, 1, 4};

    cuts.insert(cuts.begin(), 0);
    cuts.push_back(7);
    sort(cuts.begin(), cuts.end());

    int n = cuts.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // tabulate
    for (int i = n - 2; i >= 1; --i){
        for (int j = 1; j <= n - 2; ++j){
            if (i > j)
                continue;

            int mini = INT_MAX;
            for (int k = i; k <= j; ++k)
                mini = min(mini, cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j]);

            dp[i][j] = mini;
        }
    }

    cout<< dp[1][n-2];
}