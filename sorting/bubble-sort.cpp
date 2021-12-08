#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &v)
{
    for (int i = 1; i <= v.size() - 1; i++)
    {
        for (int j = 0; j <= v.size() - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main()
{
    vector<int> a;
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the array: \n";
    while (n--)
    {
        int c;
        cin >> c;
        a.push_back(c);
    }
    BubbleSort(a);
    cout << "The sorted array is: \n";
    for (auto i : a)
        cout << i << " ";
}

// 4 2 3 1 5
// Step-1
// 2 4 3 1 5