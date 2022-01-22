#include <bits/stdc++.h>
using namespace std;
// a simple binary search approach to find lower bound of a value in a given array! O(log n) time complexity
int lower_bound(vector<int> &v, int val)
{
    int n = v.size();
    int l = 0, h = n - 1;
    int mid;

    while(l<=h){
        mid = (l + h) / 2;
        if(v[mid] == val)
            return val;

        if(v[mid]<val){
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    if(l==0 & v[l]>val)
        return -1;
    else
        return v[h];
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
