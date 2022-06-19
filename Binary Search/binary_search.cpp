#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(log N) where N = size of the array

// Approach-1
int binary_search1(vector<int> arr, int to_find)
{
    int start = 0, end = arr.size() - 1, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == to_find)
            return mid;
        else if (arr[mid] < to_find)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

// Approach-2
int binary_search2(vector<int> arr, int to_find)
{
    int hi = arr.size() - 1, lo = 0;
    int mid;
    while (hi - lo > 1)
    {
        mid = lo + (lo - hi) / 2;
        if (arr[mid] < to_find)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    if (arr[lo] == to_find)
        return lo;
    if (arr[hi] == to_find)
        return hi;
    return -1;
}

int main()
{
    cout << "Enter the size of the array: " << endl;
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Enter the number of test cases: " << endl;
    int t;
    cin >> t;
    while (t--)
    {
        cout << "Enter the number to be searched: ";
        int val;
        cin >> val;
        cout << "Index found: " << binary_search1(arr, val) << endl;
    }
    return 0;
}
