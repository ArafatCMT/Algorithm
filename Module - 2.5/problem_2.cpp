#include<bits/stdc++.h>
using namespace std;

vector <int> v[1005];

void bfs(int src, int level, vector<int>&v2, vector<bool>&vis)
{
    queue <pair<int,int>> q;
    q.push({src,0});
    vis[src] = true;
    while (!q.empty())
    {
        pair<int,int> Pair = q.front();
        q.pop();
        int p = Pair.first;
        int lev = Pair.second;
        if(level == lev)
        {
            v2.push_back(p);
        }
        for(int child:v[p])
        {
            if(!vis[child])
            {
                q.push({child,lev+1});
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
    int level;
    cin>>level;
    vector <int> v2;
    vector <bool> vis(n,false);
    bfs(0,level,v2,vis);
    sort(v2.begin(),v2.end(),greater<int>());
    for(int val : v2)
    {
        cout<<val<<" ";
    }
    return 0;
}