#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int count_given_difference(int  arr[], int n, int s)
{
    if(n == 0)
    {
        if(s == 0) return 1;
        else return 0;
    }
    if(dp[n][s] != -1) return dp[n][s];
    if(arr[n-1] <= s)
    {
        int op1 = count_given_difference(arr, n-1, s - arr[n-1]);
        int op2 = count_given_difference(arr, n-1, s);
        return dp[n][s] = op1 + op2;
    }
    else
    {
       return dp[n][s] =count_given_difference(arr, n-1, s);
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
    int d;
    cin>>d;
    if((s+d) % 2 == 0)
    {
        int s1 = (d + s) / 2;
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=s1; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout<<count_given_difference(arr, n, s1)<<endl;
    }
    else
    {
        cout<<"0"<<endl;
    }
    return 0;
}