#include <bits/stdc++.h>
using namespace std;
#define ll long long

int kadanes_algo(int arr[], int n){
    int cs, ms;
    cs = ms = arr[0];

    for (int i = 1; i < n;i++){
        cs = max(arr[i], arr[i] + cs);
        if(cs> ms) // Time complexity: O(n)! doesn't take any extra space as well unlike prefix sum! O(1) space!
            ms = cs;
    }

    return ms;
}

int main()
{
    cout << "Enter the size of array! \n";
    int n;
    cin >> n;

    int arr[n];
    cout << "Enter the array! \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The max subarray sum is: \n";
    cout<<kadanes_algo(arr, n);

    return 0;
}