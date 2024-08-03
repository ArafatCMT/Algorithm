#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
bool subset_sum(int arr[], int n, int s)
{
    if(n == 0)
    {
        return s == 0;
    }
    if(dp[n][s] != -1) return dp[n][s];
    if(arr[n-1] <= s)
    {
        bool op1 = subset_sum(arr, n-1, s - arr[n-1]);
        bool op2 = subset_sum(arr, n-1, s);
        return dp[n][s] = op1 || op2;
    }
    else
    {
        return dp[n][s] = subset_sum(arr, n-1, s);
    }
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        int x = 1000 - m;
        if(x > 0)
        {
            for(int i=0; i<=n; i++)
            {
                for(int j=0; j<=x; j++)
                {
                    dp[i][j] = -1;
                }
            }
            if(subset_sum(arr,n,x))
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
            cout<<"YES"<<endl;
        }
    }
    
    return 0;
}