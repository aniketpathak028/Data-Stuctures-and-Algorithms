#include <bits/stdc++.h>

using namespace std;

int kth_largest(vector<int> arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (auto &it : arr)
    {
        min_heap.push(it);
        if (min_heap.size() > k)
            min_heap.pop();
    }
    return min_heap.top();
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
    cout << kth_largest(arr, k);
    return 0;
}