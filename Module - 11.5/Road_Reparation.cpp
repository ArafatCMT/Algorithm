#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int level[N];
bool vis[N];
vector <int> adj[N];

void dsu_initialize(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i] = i;
        level[i] = 0;
        vis[i] = false;
    }
}
int dsu_find(int node)
{
    if(parent[node] == node)
    {
        return node;
    }
    return parent[node] = dsu_find(parent[node]);
}
void dsu_union_by_level(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    
    if(level[leaderA] > level[leaderB])
    {
        parent[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        parent[leaderA] = leaderB;
    }
    else
    {
        parent[leaderA] = leaderB;
        level[leaderB]++;
    }
}
class Edge
{
    public:
        int u,v;
        ll c;
        Edge (int u, int v, ll c)
        {
            this->u = u;
            this->v = v;
            this->c = c;
        }
};
bool cmp (Edge a, Edge b)
{
    return a.c < b.c;
}
void dfs(int source)
{
    vis[source] = true;

    for(int child : adj[source])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_initialize(n);
    vector <Edge> Edgelist;
    
    while(e--)
    {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        Edgelist.push_back(Edge(u,v,c));
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int component = 0;

    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            component++;
        }
    }

    if(component > 1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        sort(Edgelist.begin(), Edgelist.end(), cmp);
        ll totalCost = 0;

        for(Edge ed : Edgelist)
        {
            int leaderA = dsu_find(ed.u);
            int leaderB = dsu_find(ed.v);

            if(leaderA != leaderB)
            {
                dsu_union_by_level(ed.u, ed.v);
                totalCost += ed.c;
            }
        }
        cout<<totalCost<<endl;
    }

    
}