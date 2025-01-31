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
        int op1 = count_subset_sum(arr, n-1, s - arr[n-1]);
        int op2 = count_subset_sum(arr, n-1, s);
        return dp[n][s] = op1 || op2;
    }
    else
    {
        return dp[n][s] = count_subset_sum(arr, n-1, s);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }
    
    if(sum % 2 == 0)
    {
        int s = sum / 2;
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=s; j++)
            {
                dp[i][j] = -1;
            }
        }

        (count_subset_sum(arr,n,s) == 1) ? cout<<"POSSIBLE"<<endl : cout<<"NOT POSSIBLE"<<endl;
    }
    else
    {
        cout<<"NOT POSSIBLE"<<endl;
    }
    return 0;
}