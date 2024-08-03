#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector <int> adj[N];
bool vis[N];
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
    vector <pair<int,int>> com;
    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            bfs(i);
            cnt++;
            com.push_back({cnt,i});
        }
    }
    cout<<com.size()-1<<endl;
    for(int i=0; i<com.size()-1; i++)
    {
        cout<<com[i].second<<" "<<com[i+1].second<<endl;
    }
    return 0;
}