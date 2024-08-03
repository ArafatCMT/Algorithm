#include<bits/stdc++.h>
using namespace std;
class Edge 
{
    public:
        int u,v,c;
        Edge(int u, int v, int c)
        {
            this->u = u;
            this->v = v;
            this->c = c;
        }
};
int main()
{
    int n,e;
    cin>>n>>e;
    vector <Edge> Edgelist;
    while (e--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        Edgelist.push_back(Edge(u,v,c));
    }
    int dis[n+1];
    for(int i=1; i<=n; i++)
    {
        dis[i] = 30000;
    }
    dis[1] = 0;
    for(int i=1; i<=n-1; i++)
    {
        for(Edge ed : Edgelist)
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if(dis[u] < 30000 && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<dis[i]<<" ";
    }
    return 0;
}