#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector <int> adj[N];
bool vis[N];
int romeo[N];
int juliet[N];

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;
    romeo[src] = 0;
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
                romeo[child] = romeo[p] + 1;
            }
        }
    }
}
void Bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;
    juliet[src] = 0;
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
                juliet[child] = juliet[p] + 1;
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
    int x,y,k;
    cin>>x>>y>>k;
    memset(vis,false,sizeof(vis));
    bfs(x);
    if(vis[y] == true)
    {
        if(romeo[y] <= k)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    memset(vis,false,sizeof(vis));
    Bfs(y);
    if(vis[x] == true)
    {
        if(juliet[y] <= k)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    // bool flag = false;
    for(int i=0; i<n; i++)
    {
        if(romeo[i] != -1 && juliet[i] != -1)
        {
            if(romeo[i] == juliet[i] && romeo[i] <= k)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}