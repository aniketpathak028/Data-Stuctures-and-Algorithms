#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n)
{

    // Time complexity of this code is: O(n/2)== O(n), as while loop runs n/2 times!
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main()
{
    cout << "Enter the size of the array! \n";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the array! \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

