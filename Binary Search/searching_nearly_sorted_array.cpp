#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target){
    int s = 0, e = nums.size() - 1, mid, n= nums.size()-1;

    while(s<=e){
        mid = s + (e - s) / 2;

        if(nums[mid]==target)
            return mid;
        else if(mid+1<=n && nums[mid+1]==target)
            return mid + 1;
        else if(mid-1>=0 && nums[mid-1]==target)
            return mid - 1;
        
        else if(nums[mid]<target)
            s = mid + 1;
        else
            e = mid - 1;
    }

    return -1;
}

int main(){
    vector<int> nums = {5, 10, 30, 20, 40};
    cout << search(nums, 20);
    return 0;
}