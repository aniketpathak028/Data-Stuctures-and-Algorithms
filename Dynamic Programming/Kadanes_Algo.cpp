//  KADANE'S ALGORITHM (MAXIMUM SUM SUBARRAY PROBLEM)

#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> a) // O(n^3)
{
    int maxi = INT_MIN;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int bruteForceOptimized(vector<int> a) // O(n^2)
{
    int maxi = INT_MIN;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int kadane(vector<int> a) // Kadane's Algorithm [O(n)]
{
    int sum = 0;
    int maxi = INT_MIN;
    for (auto i : a)
    {
        sum += i;
        maxi = max(maxi, sum);
        if (sum < 0) // there is no point in keeping a negative sum, as it is ultimately going to reduce our total sum in the future (doesn't matter we encounter a negative or a positive integer ahead)
            sum = 0;
    }
    return maxi;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << bruteForce(a) << endl;
    cout << bruteForceOptimized(a) << endl;
    cout << kadane(a) << endl;
    return 0;
}