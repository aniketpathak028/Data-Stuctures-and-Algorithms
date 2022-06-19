#include <bits/stdc++.h>

using namespace std;

vector<int> kSort(vector<int> nums, int k)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(auto &num: nums){
        min_heap.push(num);
        if(min_heap.size()>k){
            ans.push_back(min_heap.top());
            min_heap.pop();
        }
    }
    while(!min_heap.empty()){
        ans.push_back(min_heap.top());
        min_heap.pop();
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int k;
    cin >> k;
    arr= kSort(arr, k);
    for(auto &it: arr)
        cout << it<<" ";
    return 0;
}