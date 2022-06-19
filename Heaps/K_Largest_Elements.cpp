#include <bits/stdc++.h>

using namespace std;

vector<int> k_largest(vector<int> arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (auto &it : arr)
    {
        min_heap.push(it);
        if (min_heap.size() > k)
            min_heap.pop();
    }
    vector<int> ans;
    while(!min_heap.empty()){
        ans.push_back(min_heap.top());
        min_heap.pop();
    }
    reverse(ans.begin(), ans.end());
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
    auto ans = k_largest(arr, k);
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}