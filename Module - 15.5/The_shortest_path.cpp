#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
vector<int> adj[N];
bool vis[N];
int parent[N];
void bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int child : adj[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int src,des;
    cin>> src >> des;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
    {
        vis[i] = false;
        parent[i] = -1;
    }
    
    bfs(src);

    if(parent[des] != -1)
    {
        int x = des;
        vector <int> v;
        while(x != -1)
        {
            v.push_back(x);
            x = parent[x];
        }
        reverse(v.begin(),v.end());
        cout<<v.size()-1<<endl;
        for(int val : v)
        {
            cout<<val<<" ";
        }
    }
    else 
    {
        cout<<"-1"<<endl;
    }
    return 0;
}