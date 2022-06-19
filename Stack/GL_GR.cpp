// for a given vector or array at every index, find the greatest element present in its left,
// and greatest element present in its right
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<int> gl(n);
    vector<int> gr(n);

    int g = gl[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        gl[i] = g;
        if (arr[i] > g)
            g = arr[i];
    }

    g = gr[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        gr[i] = g;
        if (arr[i] > g)
            g = arr[i];
    }

    int w = 0;
    for (int i = 0; i < n; i++){
        w += min(gl[i], gr[i]) > arr[i] ? min(gl[i], gr[i]) - arr[i] : 0;
    }
    cout << endl
         << "water trapped is: " << w;
    return 0;
}