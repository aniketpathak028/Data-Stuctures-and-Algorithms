#include<bits/stdc++.h>
using namespace std;

void prime_sieve(int n)
{
    bool prefix[n+1]={false};

    for (int i = 2; i < n+1;i++)
    {
        if(!prefix[i])
        {
            for (int j = i*2; j < n + 1;j+=i)
            {
                prefix[j] = true;
            }
        }
    }

    cout << "All primes from 2 to n are: \n";
    for (int i = 2; i < n+1;i++){
        if(!prefix[i]){
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    cout << "Enter the number: \n";
    int n;
    cin >> n;

    prime_sieve(n);
    return 0;
}