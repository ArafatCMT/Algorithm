#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int adj[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>adj[i][j];
        }
    }
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}