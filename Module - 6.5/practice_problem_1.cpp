#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
int level[N];
vector<int> adj[N];

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int child:adj[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
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
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int Q;
    cin>>Q;
    while(Q--)
    {
        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));

        int src,dis;
        cin>>src>>dis;

        bfs(src);

        if(level[dis] == -1)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            cout<<level[dis]<<endl;
        }
        
    }
    return 0;
}