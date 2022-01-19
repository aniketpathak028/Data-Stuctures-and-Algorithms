#include<iostream>
using namespace std;

void fun(int i, int n){
    if(i<1) // Base condition
        return;

    cout << i << endl;
    fun(i - 1, n);
}

int main(){
    cout << "Enter a number!";
    int n;
    cin >> n;
    fun(n, n);
    return 0;
}