#include<bits/stdc++.h>
using namespace std;

void fun(int i, int a[], vector<int> &v, int n, int sum, int curr_sum)
{
    if(i==n){
        if(sum==curr_sum)
        {
        if(v.size()==0)
            cout << "{}";
        for(auto i: v)
            cout << i << " ";
        cout << endl;
        }
        return;
    }

    v.push_back(a[i]);
    curr_sum += a[i];
    fun(i + 1, a, v, n, sum, curr_sum);

    v.pop_back();
    curr_sum -= a[i];
    fun(i + 1, a, v, n, sum, curr_sum);
}

int main()
{
    int arr[] = {1, 3, 1};
    int sum = 4;
    vector<int> a;
    fun(0, arr, a, 3, 4, 0);
    return 0;
}