#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Edge
{
    public:
        int u,v;
        ll c;
        Edge(int u, int v, ll c)
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
    while(e--)
    {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        Edgelist.push_back(Edge(u,v,c));

    }
    ll dis[n];
    for(int i=1; i<=n; i++)
    {
        dis[i] = 1e18;
    }
    int src;
    cin>>src;
    dis[src] = 0;
    
    bool cycle = false;

    int test;
    cin>>test;

    while (test--)
    {
        int d;
        cin>> d;

        for(int i=1; i<=n-1; i++)
        {
            for(Edge ed : Edgelist)
            {
                int u = ed.u;
                int v = ed.v;
                ll c = ed.c;

                if(dis[u] < 1e18 && dis[u] + c < dis[v])
                {
                    dis[v] = dis[u] + c;
                }
            }
        }

        if(!cycle)
        {
            for(Edge ed : Edgelist)
            {
                int u = ed.u;
                int v = ed.v;
                ll c = ed.c;
                if(dis[u] < 1e18 && dis[u] + c < dis[v])
                {
                    cycle = true;
                    break;
                }
            }
        }

        if(!cycle)
        {
            if(dis[d] != 1e18) cout<< dis[d]<< endl;
            else cout<< "Not Possible" << endl;
        }
    }

    if(cycle) cout<<"Negative Cycle Detected"<<endl;

    return 0;
}