#include <bits/stdc++.h>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x)
{
    pair<int, int> p;
    p.first = arr[0];
    p.second = arr[1];

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (abs(x - (arr[i] + arr[j])) < abs(x - (p.first + p.second)))
            {
                p.first = arr[i];
                p.second = arr[j];
            }
        }
    }

    return p;
}

int main()
{
    cout << "Enter the size of array! \n";
    int n;
    cin >> n;
    cout << "Enter the array! \n";
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << "Enter the val! \n";
    int val;
    cin >> val;

    cout << "The pair is: \n";
    pair<int,int> ans;
    ans= closestSum(v, val);

    cout << ans.first << " " << ans.second;

    return 0;
}