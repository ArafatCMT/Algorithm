#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector <int> adj [N];
bool vis [N];
void dfs(int src)
{
    vis[src] = true;
    for(int c : adj[src])
    {
        if(vis[c] == false)
        {
            dfs(c);
        }
    }
}
int main()
{
    int node, edge;
    cin>> node >> edge;
    while(edge--)
    {
        int u,v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis,false,sizeof(vis));
    int count = 0;
    for(int i=0; i<node; i++)
    {
        if(vis[i] == false)
        {
            dfs(i);
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}