#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int val[n], w[n];
    for(int i=0; i<n; i++)
    {
        cin>>val[i];
        w[i] = i+1;
    }

    int dp[n+1][n+1];
    
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(w[i-1] <= j)
            {
                dp[i][j] = max(val[i-1] + dp[i][j - w[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n][n]<<endl;
    return 0;
}