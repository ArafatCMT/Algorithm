#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
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
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src, d, k;
    cin>>src>>d>>k;

    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));

    bfs(src);

    if(dis[d] != -1 && dis[d] <= (k*2)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}