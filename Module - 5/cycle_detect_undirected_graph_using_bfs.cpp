#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector <int> adj[N];
bool vis[N];
int parentArray [N];
bool flag = false;

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        // cout<<par<<endl;
        for(int child:adj[parent])
        {
            if(vis[child] == true && child != parentArray[parent])
            {
                flag = true;
            }
            if(!vis[child])
            {
                vis[child] = true;
                q.push(child);
                parentArray[child] = parent;
            }
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
    // bfs(2);
    for(int i=0; i<node; i++)
    {
        if(vis[i] == false)
        {
            bfs(i);
        }
    }
    (flag == true) ? cout<< "Cycle Found" : cout<< "Cycle Not Found";
    return 0;
}