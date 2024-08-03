#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int mat[N][N];
int n,x;
vector <int> adj[N];
bool vis[N];
int dis[N];
void bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int child : adj[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                dis[child] = dis[par] + 1;
            }
        }
    }
}
int main()
{
    cin>>n>>x;
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
        dis[i] = -1;
    }
    bfs(x);
    for(int i=1; i<=n; i++)
    {
        cout<<dis[i]<<" ";
    }
    return 0;
}