#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
int parent[N];
vector<int> adj[N];
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
            if(vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                parent [child] = par;
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
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    bfs(1);
    if(vis[n] == false)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        vector <int> v;
        int x = n;
        while (x != -1)
        {
            v.push_back(x);
            x = parent[x];
        }
        reverse(v.begin(),v.end());
        cout<<v.size()<<endl;
        for(int val : v)
        {
            cout<<val<<" ";
        }
    }
    return 0;
}