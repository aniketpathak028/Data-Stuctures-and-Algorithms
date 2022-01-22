#include<bits/stdc++.h>

using namespace std;

int fun(int n)
{
    if(n<=1)
        return n;

    return fun(n - 1) + fun(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout<<endl<<fun(n);
    return 0;
}