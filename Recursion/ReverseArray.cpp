#include<iostream>
using namespace std;

// single pointer
void fun(int i, int a[], int &n){
    if(i>n/2) // Base condition, swap only till the middle is reached
        return;

    swap(a[i], a[n-i-1]);  // swap the indices
    fun(i + 1, a, n);
}

// // 2 pointers
// void fun(int s, int e, int a[], int &n){
//     if(s>=e) // Base condition, swap only till the middle is reached
//         return;

//     swap(a[s], a[e]);  // swap the indices
//     fun(s+1, e-1, a, n);
// }

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++)
        cin >> a[i];

    fun(0, a, n);

    cout << "REVERSE ARRAY: ";

    for (int i = 0; i < n; i++)
        cout<< a[i]<<" ";

    return 0;
}