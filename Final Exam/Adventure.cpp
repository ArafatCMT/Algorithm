#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int knapscak(int weight[], int value[], int n, int w)
{
    if(n == 0 || w == 0)
    {
        return 0;
    }
    if(dp[n][w] != -1) return dp[n][w];
    if(weight[n-1] <= w)
    {
        int op1 = knapscak(weight, value, n-1, w - weight[n-1]) + value[n-1];
        int op2 = knapscak(weight, value, n-1, w);
        return dp[n][w] = max(op1,op2);
    }
    else
    {
        return dp[n][w] = knapscak(weight, value, n-1, w);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,w;
        cin>> n >> w;
        int weight[n], value[n];
        for(int i=0; i<n; i++)
        {
            cin>> weight[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>> value[i];
        }
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=w; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout<< knapscak(weight, value, n, w)<<endl;
    }
    return 0;
}