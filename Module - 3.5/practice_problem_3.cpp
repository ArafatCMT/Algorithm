#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
int cnt = 0;
int vis [N] = {0};
void dfs(int src)
{
    cnt++;
    vis[src] = 1;
    for(int child : adj[src])
    {
        if(vis[child] == 0)
        {
            dfs(child);
        }
    }
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    while (edge--)
    {
        int u, v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <int> v;
    for(int i=0; i<node; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i);
            v.push_back(cnt);
            cnt = 0;
        }
    }
    sort(v.begin(),v.end());
    for(int x : v)
    {
        cout<<x<<" ";
    }
    return 0;
}