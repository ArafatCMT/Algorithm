#include<bits/stdc++.h>
using namespace std;
// int dp[1005][1005];
// bool subset_sum(int arr[], int n, int s)
// {
//     if(n == 0)
//     {
//         return s == 0;
//     }
//     if(dp[n][s] != -1) return dp[n][s];
//     if(arr[n-1] <= s)
//     {
//         bool op1 = subset_sum(arr, n-1, s - arr[n-1]);
//         bool op2 = subset_sum(arr, n-1, s);
//         return dp[n][s] = op1 || op2;
//     }
//     else
//     {
//         return dp[n][s] = subset_sum(arr, n-1, s);
//     }
// }
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
    if(s % 2 == 0)
    {
        int sum = s / 2;
        int dp[n+1][sum+1];
        dp[0][0] = 1;
        for(int i=1; i<=sum; i++)
        {
            dp[0][i] = 0;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=sum; j++)
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
        
        // (subset_sum(arr,n,sum)) ? cout<<"POSSIBLE"<<endl : cout<<"NOT POSSIBLE"<<endl;
        if(dp[n][sum]) cout<<"POSSIBLE"<<endl;
        else cout<<"NOT POSSIBLE"<<endl;
    }
    else
    {
        cout<<"NOT POSSIBLE"<<endl;
    }
    return 0;
}