#include<bits/stdc++.h>
using namespace std;
const int N = 60;
vector <int> adj[N];
bool vis[N];
bool pathVisitArray[N];
bool Cycle;
void dfs(int src)
{
    vis[src] = true;
    pathVisitArray[src] = true;
    for(int child : adj[src])
    {
        if(pathVisitArray[child])
        {
            Cycle = true;
        }
        if(!vis[child])
        {
            dfs(child);
        }
    }
    pathVisitArray[src] = false;
}
int main()
{
    int n;
    cin>>n;
    int mat[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>mat[i][j];
            if(mat[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        vis[i] = false;
        pathVisitArray[i] = false;
    }
    Cycle = false;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    (Cycle) ? cout<<"1"<<endl : cout<<"0"<<endl;
    return 0;
}