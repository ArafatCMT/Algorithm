#include<bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];
int level [1005];

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
        for(int child : v[pr])
        {
            if(vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[pr] + 1;
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
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    int src;
    cin>>src;
    bfs(src);
    for(int i=0; i<n; i++)
    {
        cout<<i<<" "<<level[i]<<endl;
    }
    return 0;
}