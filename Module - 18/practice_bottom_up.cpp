#include<bits/stdc++.h>
using namespace std;
int knapsack(int n, int weight[], int value[], int w)
{
    //base case
    if(n == 0 || w == 0) return 0;
    if(weight[n-1] <= w)
    {
        int op1 = knapsack(n-1, weight, value, w - weight[n-1]) + value[n-1];
        int op2 = knapsack(n-1, weight, value, w);
        return max(op1,op2);
    }
    else
    {
        int op2 = knapsack(n-1, weight, value, w);
        return op2;
    }
}
int main()
{
    int n;
    cin>>n;
    int weight[n], value[n];
    for(int i=0; i<n; i++)
    {
        cin>>weight[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>value[i];
    }
    int w;
    cin>>w;
    // cout<<knapsack(n, weight, value, w)<<endl;
    int dp[n+1][w+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(weight[i-1] <= j)
            {
                int op1 = value[i-1] + dp[i-1][j - weight[i-1]];
                int op2 = dp[i-1][j];
                dp[i][j] = max(op1,op2);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for(int i=0; i<=n; i++)
    // {
    //     for(int j=0; j<=w; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][w]<<endl;
    return 0;
}