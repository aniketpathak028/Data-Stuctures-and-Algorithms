#include <bits/stdc++.h>
using namespace std;
// backtracking method to generate all permutations
void generate_perm(int i, vector<int> &nums, vector<bool> &vis, vector<int> res, vector<vector<int>> &perm)
{
    if (i >= nums.size())
    {
        perm.push_back(res);
        return;
    }

    for (int j = 0; j < nums.size(); ++j)
    {
        if (!vis[j])
        {
            res.push_back(nums[j]);
            vis[j] = 1;
            generate_perm(i + 1, nums, vis, res, perm);
            vis[j] = 0;
            res.pop_back();
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    auto copy = nums;
    vector<bool> vis(n, 0);
    vector<int> res;
    vector<vector<int>> perm;
    sort(nums.begin(), nums.end());
    generate_perm(0, nums, vis, res, perm);
    cout << "All permutaions are: " << endl;
    for (auto it : perm)
    {
        for (auto jt : it)
        {
            cout << jt << " ";
        }
        cout << endl;
    }
    // int idx = 0;
    // for (int i = 0; i < perm.size(); ++i)
    // {
    //     bool res = 1;
    //     for (int j = 0; j < n; ++j)
    //     {
    //         if (copy[j] != perm[i][j])
    //         {
    //             res = 0;
    //             break;
    //         }
    //     }
    //     if (res)
    //         break;
    //     else
    //         idx++;
    // }
    // cout << endl
    //      << "The index of the vector is : " << idx;
    return 0;
}