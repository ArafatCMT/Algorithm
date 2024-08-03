#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int s = 0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        s += arr[i];
    }

    int dp[n+1][s+1];
    dp[0][0] = 1;

    for(int i=1; i<=s; i++)
    {
        dp[0][i] = 0;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=s; j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector <int> v;
    for(int j=0; j<=s ; j++)
    {
        if(dp[n][j] == 1)
            v.push_back(j);
    }
    // int ans = INT_MAX;
    // for(int val : v) 
    // {
    //     int s1 = val;
    //     int s2 = s - s1;
    //     ans = min(ans,abs(s1 - s2));
    // }
    // cout<<ans<<endl;
    for(int val :v )
    {
        cout<<val<<" ";
    }
    return 0;
}