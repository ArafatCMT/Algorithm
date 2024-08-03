#include<bits/stdc++.h>
using namespace std;
void convert(int n, vector <int> adj[])
{
    int mat[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            mat[i][j] = 0;
            if(i == j) mat[i][j] = 1;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int child : adj[i])
        {
            mat[i][child] = 1;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector <int> adj[n];
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    convert(n,adj);
    return 0;
}