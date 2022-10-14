#include<bits/stdc++.h>
using namespace std;

int ceil(vector<int> &nums, int key){
    int s = 0, e = nums.size() - 1, mid, res = -1;
    while(s<=e){
        mid = s + (e - s) / 2;
        if(nums[mid]==key)
            return mid;
        else if(nums[mid]>key){
            res = mid;
            e = mid - 1;
        }else
            s = mid + 1;
    }
    return res;
}

int floor(vector<int> &nums, int key){
    int s = 0, e = nums.size() - 1, mid, res = -1;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (nums[mid] == key)
            return mid;
        else if (nums[mid] < key)
        {
            res = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return res;
}

int findMinDiff(vector<int> &nums, int key){
    int ceil_idx = ceil(nums, key), floor_idx = floor(nums, key);
    if(abs(nums[ceil_idx]-key)<abs(nums[floor_idx]-key))
        return ceil_idx;
    return floor_idx;
}

int main(){
    vector<int> nums = {2, 5, 7, 10, 12};
    cout << findMinDiff(nums, 8);
    return 0;
}