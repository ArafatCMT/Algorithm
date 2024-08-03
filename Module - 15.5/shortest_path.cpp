#include<bits/stdc++.h>
#define ll long long int
#define pi pair<ll,ll> 
using namespace std;
const int N = 2005;
vector <pi> adj[N];
ll dis[N];
int parent[N];
class cmp
{
    public:
        bool operator()(pi a, pi b)
        {
            return a.second > b.second;
        }
};
void Dijkstra(ll src)
{
    priority_queue< pi, vector<pi>, cmp> pq; 
    pq.push({src,0});
    dis[src] = 0;

    while (!pq.empty())
    {
        int node = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        for(pi child : adj[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode,dis[childNode]});
                parent[childNode] = node;
            }
        }
    }
}
int main()
{
    ll n,e;
    cin>>n>>e;
    ll src , des;
    cin>>src>> des;
    while (e--)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    for(int i=1; i<=n; i++)
    {
        parent[i] = -1;
        dis[i] = 1e18;
    }

    Dijkstra(src);

    if(dis[des] != -1)
    {
        cout<<dis[des]<<endl;
        int x = des;
        vector <int> v;
        while(x != -1)
        {
            v.push_back(x);
            x = parent[x];
        }
        reverse(v.begin(),v.end());
        for(int val : v)
        {
            cout<<val<<" ";
        }
    }
    else 
    {
        cout<<"-1"<<endl;
    }
    return 0;
}