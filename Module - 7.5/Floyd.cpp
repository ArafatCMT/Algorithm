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
                if(adj[i][k] != -1 && adj[k][j] != -1)
                {
                    if(adj[i][k] + adj[k][j] < adj[i][j])
                    {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                    if(adj[i][j] == -1)
                    {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
    }
    int mx = INT_MIN;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            mx = max(mx,adj[i][j]);
        }
    }
    cout<<mx<<endl;
    return 0;
}