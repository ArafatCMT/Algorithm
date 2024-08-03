#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    ll mat[n+1][n+1];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            mat[i][j] = 1e18;
            if(i == j) mat[i][j] = 0;
        }
    }

    while (e--)
    {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        if(c < mat[u][v]) mat[u][v] = c;
        
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(mat[i][k] != 1e18 && mat[k][j] != 1e18 && mat[i][k] + mat[k][j] < mat[i][j])
                {
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }

    int Q;
    cin>>Q;

    while (Q--)
    {
        int src,dis;
        cin >> src >> dis;

        if(mat[src][dis] == 1e18) cout<<"-1"<<endl;
        else cout<< mat[src][dis] <<endl;
    }
    return 0;
}