#include<bits/stdc++.h>
using namespace std;

vector<int> NGR(vector<int> ip)
{
    stack<int> s;
    vector<int> ans;
    for (int i = ip.size() - 1; i >= 0; i--){
        if(s.empty())
            ans.push_back(-1);
        else if(s.top()>ip[i])
            ans.push_back(s.top());
        else if(s.top()<ip[i]){
            while(!s.empty() && s.top()<=ip[i])
                s.pop();
            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(ip[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> NGL(vector<int> ip)
{
    stack<int> s;
    vector<int> ans;
    for (int i = 0; i<ip.size(); i++)
    {
        if (s.empty())
            ans.push_back(-1);
        else if (s.top() > ip[i])
            ans.push_back(s.top());
        else if (s.top() < ip[i])
        {
            while (!s.empty() && s.top() <= ip[i])
                s.pop();
            if (s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(ip[i]);
    }
    return ans;
}

vector<int> NSL(int n, int a[])
{
    vector<int> ans;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
            ans.push_back(-1);
        else if (st.top() < a[i])
            ans.push_back(st.top());
        else if (st.top() >= a[i])
        {
            while (!st.empty() && st.top() >= a[i])
                st.pop();
            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
        }
        st.push(a[i]);
    }
    return ans;
}

vector<int> NSR(int n, int a[])
{
    vector<int> ans;
    stack<int> st;
    for (int i = n-1; i >0; i--)
    {
        if (st.empty())
            ans.push_back(-1);
        else if (st.top() < a[i])
            ans.push_back(st.top());
        else if (st.top() >= a[i])
        {
            while (!st.empty() && st.top() >= a[i])
                st.pop();
            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
        }
        st.push(a[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ip(n);
    for (int i = 0; i < n; i++)
        cin >> ip[i];
    vector<int> ans = NGR(ip);
    for (int i = 0; i < n; i++)
        cout<< ans[i]<<" ";
    return 0;
}