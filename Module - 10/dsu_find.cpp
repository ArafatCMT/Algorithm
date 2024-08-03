#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
void dsu_initialize(int n)
{
    for(int i=0; i<n; i++)
    {
        par[i] = -1;
    }
    par[1] = 0;
    par[2] = 5;
    par[3] = 2;
    par[4] = 1;
    par[5] = 1;
    par[6] = 3;

}
int find(int node) // complexity : O (log n) // path comparission optimization
{
    if(par[node] == -1)
    {
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}
int main()
{
    dsu_initialize(7);
    for(int i=0; i<7; i++)
    {
        cout<<i<<" -> "<<par[i]<<endl;
    }
    cout<<find(2)<<endl;
    cout<<par[5]<<endl;
    return 0;
}