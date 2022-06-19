// https://leetcode.com/problems/target-sum/
#include<bits/stdc++.h>

using namespace std;

// Recurrence
int solve(int i, vector<int> &nums, int tar)
{
    if (i == 0)
    {
        if (nums[0] == 0 && tar == 0)
            return 2;
        if (tar == nums[0] || tar == -nums[0])
            return 1;
        return 0;
    }

    int plus = solve(i - 1, nums, tar + nums[i]);
    int minus = solve(i - 1, nums, tar - nums[i]);

    return plus + minus;
}
int findTargetSumWays(vector<int> &nums, int target)
{
    return solve(nums.size() - 1, nums, target);
}

int main()
{
    return 0;
}