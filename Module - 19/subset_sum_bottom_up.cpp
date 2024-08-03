#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int s;
    cin>>s;

    bool dp[n+1][s+1];

    for(int i=0; i<=s; i++)
    {
        if(i == 0)
        {
            dp[0][i] = true;
            continue;
        }
        dp[0][i] = false;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=s; j++)
        {
            if(arr[i-1] <= j)
            {
                bool op1 = dp[i-1][j - arr[i-1]];
                bool op2 = dp[i-1][j];
                dp[i][j] = op1 || op2;
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
    // for(int i=0; i<=n; i++)
    // {
    //     for(int  j=0; j<=s; j++)
    //     {
    //         if(dp[i][j]) cout<<"T"<<" ";
    //         else cout<<"F"<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}