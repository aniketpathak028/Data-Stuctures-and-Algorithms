#include <bits/stdc++.h>
using namespace std;

int upper_bound(vector<int> arr, int element)
{
    int lo = 0, hi = arr.size() - 1;
    int mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (arr[mid] <= element)
            lo = mid + 1;
        else
            hi = mid;
    }

    if(arr[lo]>element)
        return arr[lo];
    if(arr[hi]>element)
        return arr[hi];
    return -1;
}

int main()
{
    cout << "Enter the size of array: " << endl;
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements in the array: " << endl;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Enter the element for upper bound: " << endl;
    int ele;
    cin >> ele;
    cout << "Upper bound: " << upper_bound(arr, ele);
    return 0;
}