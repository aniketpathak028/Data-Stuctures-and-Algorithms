// find the sum of all subarrays and the subarray with the greatest sum!
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sumSubArrays(int arr[], int n)
{
    int prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n;i++){
        prefix[i] = prefix[i - 1] + arr[i];
    }
    vector<int> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = i > 0 ? prefix[j] - prefix[i - 1] : prefix[j];
            // Time complexity= O(n^2)! prefix-sum approach
            s.push_back(sum);
        }
    }

    int max = INT_MIN;
    for (auto i : s)
    {
        if (i > max)
            max = i;
    }
    cout << "The greatest sum among all subarray is : " << max << endl;
}

int main()
{
    cout << "Enter the size of array! \n";
    int n;
    cin >> n;

    int arr[n];
    cout << "Enter the array! \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sumSubArrays(arr, n);

    return 0;
}
