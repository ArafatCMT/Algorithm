#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector <int> adj[N];
bool vis[N];
int parentArray [N];
bool flag = false;

void dfs(int parent)
{
    // cout<<parent<<endl;
    vis[parent] = true;
    for(int child : adj[parent])
    {
        if(vis[child] == true && child != parentArray[parent])
        {
            flag = true;
            // cout<<parent<<" "<<parentArray[parent]<<" "<<child<<endl;
        }
        if(vis[child] == false)
        {
            parentArray[child] = parent;
            dfs(child);
        }
    }
}
int main()
{
    int node , edge;
    cin>> node >> edge;
    while (edge--)
    {
        int u , v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis,false,sizeof(vis));
    memset(parentArray,-1,sizeof(parentArray));
    // dfs(0);
    for(int i=0; i<node; i++)
    {
        if(vis[i] == false)
        {
            dfs(i);
        }
    }
    (flag == true) ? cout<< "Cycle Detected" : cout<< "Cycle Not Detected";
    return 0;
}