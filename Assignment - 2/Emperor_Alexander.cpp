#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int group_size[N];

void dsu_initialize(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if(parent[node] == -1)
    {
        return node;
    }
    return parent[node] = dsu_find(parent[node]);
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
    }

    sort (Edgelist.begin(),Edgelist.end(),cmp);

    ll totalCost = 0;
    int remove_roads = 0;

    for(Edge ed : Edgelist)
    {
        int leaderA = dsu_find(ed.u);
        int leaderB = dsu_find(ed.v);

        if(leaderA == leaderB)
        {
            remove_roads++;
        }
        else
        {
            dsu_union_by_size(ed.u, ed.v);
            totalCost += ed.c;
        }
    }

    int cmpnt = 0;
    //cheak component
    for(int i=1; i<=n; i++)
    {
        if(parent[i] == -1)
        {
            cmpnt++;
        }
    }

    if(cmpnt == 1)
    {
        cout<<remove_roads<<" "<<totalCost;
    }
    else
    {
        cout<<"Not Possible"<<endl;
    }
    return 0;
}