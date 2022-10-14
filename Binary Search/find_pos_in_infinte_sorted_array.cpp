#include<bits/stdc++.h>
using namespace std;

int findEle(vector<int> nums, int ele){
    int s = 0, e = s + 1, mid;
    
    while(nums[e]<ele){
        s = e;
        e = 2 * e;
    }
    
    while(s<=e){
        mid = s + (e - s) / 2;
        if(nums[mid]==ele)
            return mid;
        else if (nums[mid] < ele)
            s = mid + 1;
        else
            e = mid - 1;
    }
    
    return -1;
}

int main(){
    // assuming that we created an infinte array
    vector<int> nums(1000);
    iota(std::begin(nums), std::end(nums), 0);
    cout << findEle(nums, 12);
    return 0;
}