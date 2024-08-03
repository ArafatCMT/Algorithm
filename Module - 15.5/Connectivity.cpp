#include<bits/stdc++.h>
using namespace std;
const int N = 105;
bool vis[N];
vector <int> adj[N];
void dfs(int src)
{
    vis[src] = true;
    for(int child : adj[src])
    {
        if(!vis[child])
        {
            dfs(child);
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
    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            cnt++;
        }
    }
    if(cnt == 1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}