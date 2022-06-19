#include<bits/stdc++.h>

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

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> mt(n, vector<int>(m));
    for (int j = 0; j < m; j++)
        mt[0][j] = matrix[0][j] == '1' ? 1 : 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
                mt[i][j] = 1 + mt[i - 1][j];
            else
                mt[i][j] = 0;
        }
    }
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, maxHist(mt[i], m));
    return maxi;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    cout << "Maximum area of Binary Matrix is: " << maximalRectangle(mat);
    return 0;
}