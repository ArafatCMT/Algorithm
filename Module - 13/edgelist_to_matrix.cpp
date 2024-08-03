#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    int mat[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            mat[i][j] = -1;
            if(i == j) mat[i][j] = 0;
        }
    }
    while(e--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        mat[u][v] = c;
        mat[v][u] = c;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}