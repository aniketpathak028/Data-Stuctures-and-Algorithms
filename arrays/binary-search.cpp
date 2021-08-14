#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int k)
{

    int s = 0;
    int e = n - 1;
    int mid;
    // time-complexity: O(log n), as the length of the array halves every time while loop runs !
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (arr[mid] == k)
            return mid;
        else if (k > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return -1;
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
    cout << endl;
    cout << "Enter the element to be searched! \n";
    int k;
    cin >> k;

    if(binary_search(arr, n, k)){
        cout << "The element was found at index " << binary_search(arr, n, k) << endl;
    }
    else{
        cout << "The element is NOT present in the array ! " << endl;
    }

    return 0;
}
