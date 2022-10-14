#include<bits/stdc++.h>
using namespace std;

int rsa(vector<int> &arr){
    int start = 0, end = arr.size() - 1, mid;
    int prev, next, n = arr.size();
    if(arr[start]<arr[end])
        return start;
    while(start<=end){
        mid = start + (end - start) / 2;
        prev = (mid + n - 1) % n, next = (mid + 1) % n;
        if(arr[mid]<arr[prev] && arr[mid]<arr[next])
            return mid;
        if(arr[mid]>arr[end])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main(){
    vector<int> arr = {4, 5, 0, 1, 2, 3};
    cout << rsa(arr);
    return 0;
}