#include<bits/stdc++.h>
using namespace std;

vector <int> v[1005];
bool vis[1005];
int level [1005];
int parent[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int pr = q.front();
        q.pop();
        for(int child:v[pr])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[pr] + 1;
                parent[child] = pr;
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
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int Q;
    cin>>Q;
    while (Q--)
    {
        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));
        memset(parent,-1,sizeof(parent));
        int src,dis;
        cin>>src>>dis;
        bfs(src);
        if(level[dis] == -1)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            cout<<level[dis]<<endl;;
        }
    }
    
    return 0;
}