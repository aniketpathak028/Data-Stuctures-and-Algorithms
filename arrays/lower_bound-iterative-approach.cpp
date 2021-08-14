#include <bits/stdc++.h>
using namespace std;
// a simple iterative approach to find lower bound of a value in a given array! O(n) time complexity
int lower_bound(vector<int> &v, int val)
{
    int lb = INT_MIN;
    int n = v.size();

    for (int i = 0; i < n;i++)
    {
        lb = (v[i] > lb && v[i] < val) ? v[i] : lb;
    }

    if(lb== INT_MIN){
        return -1;
    }

    return lb;
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

    cout << "Enter the val, whose lower bound to be found in the array! \n";
    int val;
    cin >> val;

    cout << "The lower bound of the given value in the array is: " << lower_bound(v, val);

    return 0;
}