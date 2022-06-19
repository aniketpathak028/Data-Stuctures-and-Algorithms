#include <bits/stdc++.h>

using namespace std;

// T.C = O(nlog(k)) as there are always k elements in the heap, never more than k!
int kth_smallest(vector<int> arr, int k){
    priority_queue<int> max_heap;
    for(auto &it: arr){
        max_heap.push(it);
        if(max_heap.size()>k)
            max_heap.pop();
    }
    return max_heap.top();
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
    cout << kth_smallest(arr, k);
    return 0;
}