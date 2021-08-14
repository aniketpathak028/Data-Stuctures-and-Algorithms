#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    cout << "Enter the size of array! \n";
    int n;
    cin >> n;
    cout << "Enter the array! \n";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The pairs possible are as follows: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << arr[i] << "," << arr[j]<<endl;
        }
        cout << endl;
    }
    //complexity 0(n^2)

    return 0;
}
