#include <bits/stdc++.h>

using namespace std;

bool fun(int i, int a[], vector<int> &v, int n, int sum, int curr_sum)
{
    if (i == n)
    {
        if (curr_sum == sum)
        {
            if (v.size() == 0)
                cout << "{}";
            for (auto i : v)
                cout << i << " ";

            cout << endl;
            return true;
        }
        return false;
    }

    v.push_back(a[i]);
    curr_sum += a[i];
    if (fun(i + 1, a, v, n, sum, curr_sum))
        return true;

    v.pop_back();
    curr_sum -= a[i];
    if (fun(i + 1, a, v, n, sum, curr_sum))
        return true;

    return false;
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
    vector<int> a;
    fun(0, arr, a, n, sum, 0);
    return 0;
}