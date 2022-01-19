#include<iostream>
using namespace std;

void fun(int i, int n){
    if(i>n) // Base condition
        return;

    fun(i + 1, n);  // backtracking - calling the function before printing ensures operation is performed in reverse order ie. N to 1 is printed
    cout << i << endl;
}

int main(){
    cout << "Enter a number!";
    int n;
    cin >> n;
    fun(1, n);
    return 0;
}