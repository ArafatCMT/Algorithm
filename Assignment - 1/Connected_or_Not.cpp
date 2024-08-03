#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];

bool bfs(int src, int dis)
{
    if(src == dis) return true;
    queue <int> q;
    q.push(src);
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int child : adj[p])
        {
            if(child == dis)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int node , edge;
    cin >> node >> edge;
    while (edge--)
    {
        int u , v;
        cin>> u >> v;
        adj[u].push_back(v);
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        int src , dis;
        cin >> src >> dis;

        (bfs(src,dis)) ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    }
    
    return 0;
}