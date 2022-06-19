// find the sum of all subarrays and the subarray with the greatest sum!
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sumSubArrays(int arr[], int n)
{
    vector<int> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                // Time complexity= O(n^3)! NAIVE APPROACH or BRUTE FORCE APPROACH
                sum += arr[k];
            }
            s.push_back(sum);
        }
    }

    int max = INT_MIN;
    for (auto i: s){
        if(i>max)
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
