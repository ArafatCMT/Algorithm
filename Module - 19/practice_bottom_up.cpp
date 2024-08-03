#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int count_subset_sum(int arr[], int n, int s)
{
    if(n == 0)
    {
        if(s == 0) return 1;
        else return 0;
    }
    if(dp[n][s] != -1) return dp[n][s];
    if(arr[n-1] <= s)
    {
        int op1 = count_subset_sum(arr,n-1,s-arr[n-1]);
        int op2 = count_subset_sum(arr, n-1, s);
        return dp[n][s] = op1 + op2;
    }
    else
    {
        return dp[n][s] = count_subset_sum(arr,n-1,s);
    }
}
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
    int diff;
    cin>> diff;
    // if((s + diff) % 2 == 0)
    // {
    //     int sum = (s+diff) / 2;
    //     for(int i=0; i<=n; i++)
    //     {
    //         for(int j=0; j<=sum; j++)
    //         {
    //             dp[i][j] = -1;
    //         }
    //     }
    //     cout<<count_subset_sum(arr,n,sum);
    // }
    // else
    // {
    //     cout<<"NOT POSSIBLE"<<endl;
    // }
    if((s+diff) % 2 == 0)
    {
        int sum = (s+diff) / 2;
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
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else
                {
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        cout<<dp[n][sum]<<endl;
    }
    else
    {
        cout<<"NOT POSSIBLE"<<endl;
    }
    return 0;
}