#include<bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];

void bfs(int src)
{
    queue<pair<int, int>> q;
    q.push({src,0});
    vis[src] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int pr = p.first;
        int level = p.second;

        cout<<pr<<" "<<level<<endl;
        
        for(int child : v[pr])
        {
            if(vis[child] == false)
            {
                q.push({child,level+1});
                vis[child] = true;
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
    int src;
    cin>>src;
    bfs(src);
    return 0;
}