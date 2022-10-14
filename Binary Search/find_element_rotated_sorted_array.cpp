#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr){
    int n = arr.size(), start = 0, end = arr.size() - 1, mid, prev, next;

    // incase the entire array is sorted
    if(arr[start]<arr[end])
        return 0;

    while(start<=end){
        mid = start + (end - start) / 2;
        prev = (mid + n - 1) % n;
        next = (mid + 1) % n;
        
        if(arr[mid]<arr[prev] && arr[mid]<arr[next])
            return mid;

        // if the mid is in between a sorted portion, then we should check left for minimum
        if(arr[mid]<arr[end]) 
            end = mid - 1;

        // else for the unsorted portion
        else
            start = mid + 1;
    }
    return -1;
}

int findElement(vector<int> &arr, int ele){
    int pos = findMin(arr);
    if(binary_search(arr.begin(), arr.begin()+pos, ele)!=-1)
        return lower_bound(arr.begin(), arr.begin() + pos, ele) - arr.begin();
    auto it = arr.begin() + pos + 1;
    int res = lower_bound(it, arr.end(), ele) - it;
    return pos+res;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 1, 2, 3};
    cout << findMin(arr)<<" ";
    cout << findElement(arr, 2);
}