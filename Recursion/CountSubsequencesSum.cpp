#include <bits/stdc++.h>

using namespace std;

int fun(int i, int a[], int n, int sum, int curr_sum)
{
    if (i == n)
    {
        if (curr_sum == sum)
        {
            return 1;
        }
        return 0;
    }
    curr_sum += a[i];
    int l = fun(i + 1, a, n, sum, curr_sum);

    curr_sum -= a[i];
    int r = fun(i + 1, a, n, sum, curr_sum);

    return l + r;
}

int main()
{
    int n;
    cout << "Enter the size of array: " << endl;
    cin >> n;
    int arr[n];
    int sum;
    cout << "Enter the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the desired sum: " << endl;
    cin >> sum;
    cout << fun(0, arr, n, sum, 0);
    return 0;
}