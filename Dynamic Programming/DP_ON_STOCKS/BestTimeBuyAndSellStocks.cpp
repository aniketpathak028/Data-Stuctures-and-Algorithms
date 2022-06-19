#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    int least_price = price[0];
    int max_profit, curr_profit;
    max_profit = curr_profit = 0;
    for (int i = 1; i < n; i++){
        curr_profit = price[i] - least_price;
        if(curr_profit>max_profit)
            max_profit = curr_profit;
        if(price[i]<least_price)
            least_price = price[i];
    }
    cout<<max_profit;
    return 0;
}