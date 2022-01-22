#include<bits/stdc++.h>

using namespace std;

bool fun(string &s, int i, int size)
{
    if(i>size/2)
        return true;

    if(s[i] == s[size-i-1])
        return fun(s, i+1, size);
    else
        return false;
}

int main()
{
    string s;
    cin >> s;
    int size = s.size();
    if(fun(s, 0, size))
        cout << "It's a palindrome";
        else
            cout << "Not a palindrome";
    return 0;
}