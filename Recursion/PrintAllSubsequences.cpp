#include<bits/stdc++.h>

using namespace std;

void fun(int i, int a[], vector<int> &v, int n)
{
    if(i==n){
        if(v.size()==0)
            cout << "{}";
        for(auto i: v)
            cout << i << " ";

        cout << endl;
        return;
    }

    v.push_back(a[i]);
    fun(i + 1, a, v, n);

    v.pop_back();
    fun(i + 1, a, v, n);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;  i++)
    {
        cin >> arr[i];
    }
    vector<int> a;
    fun(0, arr, a, n);
    return 0;
}