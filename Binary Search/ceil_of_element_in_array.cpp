#include<bits/stdc++.h>
using namespace std;

int findCeil(vector<int> &nums, int num){
    int s = 0, e = nums.size() - 1, mid, res = -1, n= nums.size();
    while(s<=e){
        mid = s + (e - s) / 2;
        if(nums[mid]==num)
            return nums[mid];
        else if(nums[mid]>num){
            res = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    if(res==-1)
        return -1;
    return nums[res];
}

int main(){
    vector<int> nums = {2, 3, 4, 6, 8, 10, 11};
    cout << findCeil(nums, 7);
    return 0;
}