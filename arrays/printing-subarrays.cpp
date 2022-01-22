#include <bits/stdc++.h>
using namespace std;
#define ll long long

void printSubArrays(int arr[], int n){

    cout << "All possible sub-arrays are: \n";
    for (int i = 0; i < n;i++){
        for (int j = i; j < n;j++){
            for (int k = i; k <= j;k++){
                cout << arr[k] << " "; // Time complexity= O(n^3)!
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter the size of array! \n";
    int n;
    cin >> n;

    int arr[n];
    cout << "Enter the array! \n";
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }

    printSubArrays(arr, n);

    return 0;
}
