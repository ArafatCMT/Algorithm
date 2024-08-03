#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int parent[N];
int group_size[N];
void dsu_initialize(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i] = i;
        group_size[i] = -1;
    }
}
int dsu_find(int node)
{
    if(parent[node] == node)
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
int main()
{
    int n;
    cin>>n;
    dsu_initialize(n);
    queue <pair<int,int>> q;
    for(int i=1; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if(leaderA == leaderB)
        {
            q.push({a,b});
        }
        else
        {
            dsu_union_by_size(a,b);
        }
    }
    cout<<q.size()<<endl;
    for(int j=2; j<=n; j++)
    {
        int leaderA = dsu_find(1);
        int leaderB = dsu_find(j);
        if(leaderA != leaderB)
        {
            cout<<q.front().first<<" "<<q.front().second<<" "<<"1"<<" "<<j<<" ";
            q.pop();
            dsu_union_by_size(1,j);
        }
    }
    return 0;
}