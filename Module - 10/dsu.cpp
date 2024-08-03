#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int group_size[N];
int level[N];
void dsu_initialize(int n)
{
    for(int i=0; i<n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }   
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
void dsu_union_by_size(int node1, int node2)
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
void dsu_union_by_level(int node1, int node2)
{
    int leader_A = dsu_find(node1);
    int leader_B = dsu_find(node2);
    if(level[leader_A] > level[leader_B])
    {
        par[leader_B] = leader_A;
    }
    else if(level[leader_B] > level[leader_A])
    {
        par[leader_A] = leader_B;
    }
    else
    {
        par[leader_A] = leader_B;
        level[leader_B]++;
    }
}
int main()
{
    dsu_initialize(7);
    // union by group 
    // //group - 1
    // dsu_union_by_size(0,1);
    // dsu_union_by_size(1,2);
    // dsu_union_by_size(2,3);
    // //group - 2
    // dsu_union_by_size(5,4);
    // dsu_union_by_size(5,6);
    // //union by 2 different group
    // dsu_union_by_size(3,6);

    // cout<<dsu_find(6);

    // union by level 
    //group - 1
    dsu_union_by_level(0,1);
    dsu_union_by_level(1,2);
    dsu_union_by_level(2,3);
    //group - 2
    dsu_union_by_level(5,4);
    dsu_union_by_level(5,6);
    //union by 2 different group
    dsu_union_by_level(3,6);

    cout<<dsu_find(1)<<endl;
    
    cout<<level[4];
    return 0;
}