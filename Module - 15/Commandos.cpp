#include<bits/stdc++.h>
using namespace std;
const int N = 105;
bool vis[N];
int dis_from_src[N];
int dis_from_des[N];
vector <int> adj[N];
void bfs(int src, int track)
{
    queue <int> q;
    q.push(src);
    if(track == 1)
    {
        dis_from_src[src] = 0;
    }
    else
    {
        dis_from_des[src] = 0;
    }
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int child : adj[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                if(track == 1)
                {
                    dis_from_src[child] = dis_from_src[par] + 1;
                }
                else
                {
                    dis_from_des[child] = dis_from_des[par] + 1;
                }
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    int cs = 1;
    while(t--)
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
        int src,des;
        cin>>src>>des;
        for(int i=0; i<n; i++)
        {
            vis[i] = false;
            dis_from_src[i] = -1;
        }
        bfs(src,1);
        for(int i=0; i<n; i++)
        {
            vis[i] = false;
            dis_from_des[i] = -1;
        }
        bfs(des,2);
        int ans = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int val = dis_from_src[i] + dis_from_des[i];
            ans = max(val,ans);
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;
        for(int i=0; i<n; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}