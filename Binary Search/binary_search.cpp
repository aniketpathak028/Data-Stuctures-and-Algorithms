#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &arr, int element){
    int start = 0, end = arr.size()-1, mid;
    while(start<=end){
        mid = start + (end - start) / 2;
        if(arr[mid]==element)
            return mid;
        else if(element<arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main(){
    vector<int> arr = {1, 2, 4, 9, 13, 45};
    cout << binary_search(arr, 45);
    return 0;
}