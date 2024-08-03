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
    int dis[n];
    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }
    int src;
    cin>>src;
    dis[src] = 0;
    for(int i=1; i<=n-1; i++)
    {
        for(Edge ed : Edgelist)
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if(dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool Cycle = false;
    for(Edge ed: Edgelist)
    {
        int u = ed.u;
        int v = ed.v;
        int c = ed.c;
        if(dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            Cycle = true;
            break;
        }
    }
    if(Cycle)
    {
        cout<<"Cycle Detected. No Answer";
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            cout<<i<<" -> "<<dis[i]<<endl;
        }
    }
    return 0;
}