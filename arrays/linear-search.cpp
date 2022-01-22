#include<iostream>
using namespace std;

int linear_search(int arr[], int n, int k){

    for (int i = 0; i < n;i++){
        if(arr[i]==k)
            return i;
    } // Time complexity = O(n) as for loop runs n times in the worst case!

    return -1;
}
int main(){
    cout << "Enter the size of array! \n";
    int n;
    cin >> n;
    cout<<"Enter the array! \n";
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    cout << "Enter the key to be searched! \n";
    int k;
    cin >> k;
    if(linear_search(arr,n,k)){
        cout << "The element was found at " << linear_search(arr, n, k) << " position! \n";
    }else
        cout << "The element was NOT found! \n";

    return 0;
}