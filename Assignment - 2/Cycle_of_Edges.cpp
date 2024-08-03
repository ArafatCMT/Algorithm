#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_size[N];
void dsu_initialize(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i] = i;
        group_size[i] = 1;
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
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_initialize(n);
    int Cycle_cnt = 0;
    while (e--)
    {
        int u,v;
        cin>>u>>v;
        int leaderA = dsu_find(u);
        int leaderB = dsu_find(v);

        if(leaderA == leaderB)
        {
            Cycle_cnt++;
        }
        else
        {
            dsu_union_by_size(u,v);
        }
    }
    cout<<Cycle_cnt<<endl;
    return 0;
}