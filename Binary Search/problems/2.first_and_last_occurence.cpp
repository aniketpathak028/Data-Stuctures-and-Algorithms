#include<bits/stdc++.h>
using namespace std;

vector<int> fnl(vector<int> arr, int n){
    vector<int> ans;
    int first = -1, last = -1;
    // finding first occurence
    int start = 0, end = arr.size() - 1, mid;
    while(start<=end){
        mid = start + (end - start) / 2;
        if(arr[mid]==n){
            end = mid - 1;
            first = mid;
        }
        else if(arr[mid]<n)
            start = mid + 1;
        else
            end = mid - 1;
    }
    ans.push_back(first);
    // finding last occurence
    start = 0, end = arr.size() - 1;
    while(start<=end){
        mid = start + (end - start) / 2;
        if(arr[mid]==n){
            start = mid + 1;
            last = mid;
        }
        else if(arr[mid]<n)
            start = mid + 1;
        else
            end = mid - 1;
    }
    ans.push_back(last);
    
    return ans;
}

int main(){
    vector<int> arr = {2, 3, 3, 4, 5, 5, 5, 9, 11};
    int n;
    cin >> n;
    auto ans = fnl(arr, n);
    cout << "The first and last occurence of " << n << " is: " << ans[0] << " "<< ans[1];
    return 0;
}