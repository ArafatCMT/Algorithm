#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector <int> adj[N];
int cnt = 0;
bool vis[N];

void dfs(int src)
{
    cnt++;
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
    while (edge--)
    {
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cin>>src;
    memset(vis,false,sizeof(vis));
    dfs(src);
    cout<<cnt<<endl;
    return 0;
}