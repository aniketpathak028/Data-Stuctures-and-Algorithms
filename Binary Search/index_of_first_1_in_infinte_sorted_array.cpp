#include<bits/stdc++.h>
using namespace std;

int findIndex(vector<int> &nums){
    int s = 0, e = s + 1, mid;
    // find the range of elements
    while(!nums[e]){
        s = e;
        e = 2 * e;
    }

    int res = -1;
    while(s<=e){
        mid = s + (e - s) / 2;
        if(nums[mid]==1){
            res = mid;
            e = mid - 1;
        }else
            s = mid + 1;
    }
    return res;
}

int main(){
    // assume that nums is an infinte binary sorted array
    vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    cout << findIndex(nums);
    return 0;
}