#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector <int> adj[N];
bool vis[N];
bool flag;
bool pathVisitArray[N];
void dfs(int parent)
{
    // cout<<parent<<endl;
    vis[parent] = true;
    pathVisitArray[parent] = true;
    for(int child:adj[parent])
    {
        if(pathVisitArray[child] == true)
        {
            flag = true;
        }
        if(vis[child] == false)
        {
            dfs(child);
        }
    }
    pathVisitArray[parent] = false;
}

int main()
{
    int node,edge;
    cin>>node>>edge;
    while (edge--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    memset(vis,false,sizeof(vis));
    memset(pathVisitArray,false,sizeof(pathVisitArray));
    flag = false;
    for(int i=0; i<node; i++)
    {
        if(vis[i] == false)
        {
            dfs(i);
        }
    }
    if(flag == true) cout<<"Cycle Detected";
    else cout<<"Cycle Not Detected";
    return 0;
}