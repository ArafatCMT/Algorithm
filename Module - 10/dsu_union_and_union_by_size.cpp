#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int group_size[N];
void dsu_initialize(int n)
{
    for(int i=0; i<n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
    // par[1] = 0;
    // par[2] = 1;
    // par[3] = 2;
    // par[5] = 4;
    // par[6] = 5;
    // par[7] = 6;
    // par[8] = 7;
}
int dsu_find(int node)
{
    if(par[node] == -1)
    {
        return node;
    }
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union(int node1, int node2) // bad 
{
    int leader_A = dsu_find(node1);
    int leader_B = dsu_find(node2);
    par[leader_B] = leader_A;
}
void dsu_union_by_size(int node1, int node2) // optimize version
{
    int leader_A = dsu_find(node1);
    int leader_B = dsu_find(node2);
    if(group_size[leader_A] > group_size[leader_B])
    {
        par[leader_B] = leader_A;
        group_size[leader_A] += group_size[leader_B];
    }
    else
    {
        par[leader_A] = leader_B;
        group_size[leader_B] += group_size[leader_A];
    }
}
int main()
{
    dsu_initialize(7);
    // cout<<"union er age 6 er leader : "<<dsu_find(6)<<endl; // union er age
    // dsu_union(3,6);
    // cout<<"union er pore 6 er leader : "<<dsu_find(6)<<endl;// union er pore
    dsu_union_by_size(0,1);
    dsu_union_by_size(1,2);
    dsu_union_by_size(2,3);
    dsu_union_by_size(3,4);
    dsu_union_by_size(4,5);
    dsu_union_by_size(5,6);
    cout<<dsu_find(6)<<endl;
    cout<<group_size[1]<<endl;
    return 0;
}