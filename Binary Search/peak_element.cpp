#include<bits/stdc++.h>
using namespace std;

int peak(vector<int> &nums){
    int s = 0, e = nums.size() - 1, mid, n = nums.size() - 1;
    while(s<=e){
        mid = s + (e - s) / 2;
        if(mid>0 && mid<n-1){
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
                return mid;
            else if(nums[mid+1]>nums[mid])
                s = mid + 1;
            else
                e = mid - 1;
        }
        else if(mid==0){
            if(nums[0]>nums[1])
                return 0;
            else
                return 1;
        }
        else if(mid==n-1){
            if(nums[n-1]>nums[n-2])
                return n - 1;
            else
                return n - 2;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {3, 7, 2, 10, 30, 15};
    cout << peak(nums);
    return 0;
}