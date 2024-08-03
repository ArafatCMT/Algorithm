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
    vector<pair<int,int>> adj[n];
    while(e--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    vector<Edge> edge;
    for(int i=0; i<n; i++)
    {
        for(pair<int,int> child : adj[i])
        {
            int childNode = child.first;
            int cost = child.second;
            edge.push_back(Edge(i,childNode,cost));
        }
    }
    for(Edge ed : edge)
    {
        cout<<ed.u<<" "<<ed.v<<" "<<ed.c<<" "<<endl;
    }
    return 0;
}