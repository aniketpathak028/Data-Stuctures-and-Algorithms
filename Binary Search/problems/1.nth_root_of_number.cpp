#include <bits/stdc++.h>
using namespace std;

double multiply(double num, int n){
    double ans = 1;
    while(n--)
        ans *= num;
    return ans;
}

double nthRoot(int num, int n)
{
    double lo = 1, hi = num, mid;
    double eps = 1e-9;
    while(hi-lo>eps){
        mid = lo + (hi - lo) / 2;
        if(multiply(mid, n)>num)
            hi = mid;
        else
            lo = mid;
    }
    return lo;
}

int main()
{
    cout << "Enter the number: ";
    int num;
    cin >> num;
    cout << "Enter the value of n: ";
    int n;
    cin >> n;
    cout << "Nth root of the number is : " << setprecision(10) << nthRoot(num, n);
    return 0;
}
