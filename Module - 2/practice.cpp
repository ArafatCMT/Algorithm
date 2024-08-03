#include<bits/stdc++.h>
using namespace std;

vector <int> v[1005];
bool vis[1005];
int level[1005];
int parent[1005];

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int pr = q.front();
        q.pop();
        // cout<<pr<<endl;
        for(int child:v[pr])
        {
            if(vis[child] == false)
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
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src,des;
    cin>>src>>des;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    bfs(src);
    // for(int i=0; i<n; i++)
    // {
    //     cout<<i<<" "<<level[i]<<endl;
    // }
    int x = des;
    vector<int> Path;
    while(x != -1)
    {
        Path.push_back(x);
        x = parent[x];
    }
    reverse(Path.begin(),Path.end());
    for(int val: Path)
    {
        cout<<val<<" ";
    }
    return 0;
}