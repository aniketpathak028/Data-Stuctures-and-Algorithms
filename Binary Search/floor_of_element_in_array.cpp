#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &nums, int num){
    int s = 0, e = nums.size() - 1, mid, res = -1, n = nums.size() - 1;
    while(s<=e){
        mid = s + (e - s) / 2;
        if(nums[mid]==num)
            return nums[mid];
        else if(nums[mid]<num){
            res = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return nums[res];
}

int main(){
    vector<int> nums = {1, 2, 4, 5, 7, 9, 13};
    cout << findFloor(nums, 6);
    return 0;
}