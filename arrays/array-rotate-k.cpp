#include <bits/stdc++.h>
using namespace std;

vector<int> kRotate(vector<int> a, int k)
{
    while (k--)
    {
        int last = a[a.size() - 1];
        for (int i = a.size() - 1; i >= 0; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = last;
    }

    return a;
}

int main(){
    cout<<"Enter the size of array! \n";
    int n;
    cin >> n;
    vector<int> v;

    cout << "Enter the array! \n";
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << "Enter the value of k! \n";
    int k;
    cin >> k;

    cout << "The resultant array is: \n";
    vector<int> a= kRotate(v, k);

    for(auto i:a)
        cout << i << " ";

    return 0;
}