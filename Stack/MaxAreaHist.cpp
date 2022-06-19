#include <bits/stdc++.h>

using namespace std;

vector<int> SSL(vector<int> arr, int n)
{
    vector<int> ans;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
            ans.push_back(i - 0 + 1);
        else if (arr[st.top()] < arr[i])
            ans.push_back(i - st.top());
        else if (arr[st.top()] >= arr[i])
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                ans.push_back(i - 0 + 1);
            else
                ans.push_back(i - st.top());
        }
        st.push(i);
    }
    return ans;
}

vector<int> SSR(vector<int> arr, int n)
{
    vector<int> ans;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
            ans.push_back(n - i);
        else if (arr[st.top()] < arr[i])
            ans.push_back(st.top() - i);
        else if (arr[st.top()] >= arr[i])
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                ans.push_back(n - i);
            else
                ans.push_back(st.top() - i);
        }
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int maxHist(vector<int> a, int n)
{
    auto ssl = SSL(a, n);
    auto ssr = SSR(a, n);
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, a[i] * (ssr[i] + ssl[i] - 1));
    return maxi;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << endl<< "Maximum area histogram is : " << maxHist(a, n);
    return 0;
}