#include<iostream>
using namespace std;

void fun(int i, int n){
    if(i>n) // Base condition
        return;

    cout << "Aniket" << endl;
    fun(i + 1, n);
}

int main(){
    cout << "Enter a number!";
    int n;
    cin >> n;
    fun(1, n);
    return 0;
}