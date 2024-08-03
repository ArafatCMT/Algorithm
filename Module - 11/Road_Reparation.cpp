#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int group_size[N];
bool vis[N];
vector <int> adj[N];
void dsu_initialize(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
        vis[i] = false;
    }
}

int dsu_find(int node)
{
    if(parent[node] == -1)
    {
        return node;
    }
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if(group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
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
void dfs(int src)
{
    vis[src] = true;
    for(int child : adj[src])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
}
bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
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
    if(component == 1)
    {
        sort(Edgelist.begin(),Edgelist.end(),cmp);
        ll minimuCost = 0;

        for(Edge ed : Edgelist)
        {
            int leaderA = dsu_find(ed.u);
            int leaderB = dsu_find(ed.v);

            if(leaderA != leaderB)
            {
                dsu_union_by_size(ed.u, ed.v);
                minimuCost += ed.c;
            }
        }
        cout<<minimuCost<<endl;
    }

    else
    {
       cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}