#include<bits/stdc++.h>
#define ll long long int 
#define pi pair<int,long long int>
using namespace std;
const int N = 1e5 + 5;
ll dis[N];
vector<pi> adj[N];
class cmd
{
    public:
        bool operator()(pi a, pi b)
        {
            return a.second > b.second;
        }
};
void Dijkstra(int src)
{
    priority_queue<pi,vector<pi>,cmd> pq;
    pq.push({src,0});
    dis[src] = 0;

    while(!pq.empty())
    {
        pi par = pq.top();
        pq.pop();
        int node = par.first;
        ll cost = par.second;
        // cout<<par.first<<endl;
        for(pi child : adj[node])
        {
            int childNode = child.first;
            ll childCost = child.second;

            if(cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode,dis[childNode]});
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    for(int i=1; i<=n; i++)
    {
        dis[i] = 1e18;
    }
    Dijkstra(1);
    for(int i=1; i<=n; i++)
    {
        cout<<dis[i]<<" ";
    }
    
    return 0;
}