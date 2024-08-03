#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
int dis[N];
int par[N];

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 1;
    
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int child : adj[p])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                par[child] = p;
                dis[child] = dis[p] + 1;
            }
        }
    }
    
}
int main()
{
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    memset(par,-1,sizeof(par));
    bfs(1);
    
    if(dis[n] == -1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        vector<int> v;
        int x = n;
        while(x != -1)
        {
            v.push_back(x);
            x = par[x];
        }
        reverse(v.begin(),v.end());
        cout<<dis[n]<<endl;
        for(int val : v)
        {
            cout<<val<<" ";
        }
    }
    return 0;
}