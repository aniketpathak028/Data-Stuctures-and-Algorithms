#include<iostream>
using namespace std;

void fun(int i, int n){
    if(i<1) // Base condition
        return;

    fun(i - 1, n);  // backtracking - calling the function before printing ensures operation is performed in reverse order ie. 1 to N is printed
    cout << i << endl;
}

int main(){
    cout << "Enter a number!";
    int n;
    cin >> n;
    fun(n, n);
    return 0;
}