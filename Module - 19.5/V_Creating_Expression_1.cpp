#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{
    ll n, x;
    cin>>n>>x;
    ll arr[n];
    ll sum = 0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }
    if((sum + x) % 2 == 0)
    {
        ll s = (sum + x) / 2;
        bool dp[n+1][s+1];
        dp[0][0] = true;
        for(int i=1; i<=s; i++)
        {
            dp[0][i] = false;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=s; j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][s])
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}