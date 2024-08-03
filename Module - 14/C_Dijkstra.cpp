#include<bits/stdc++.h>
#define ll long long int 
#define pi pair<ll,ll>
using namespace std;
const int N = 1e5 + 5;
ll dis[N];
ll parent[N];
vector <pi> adj[N];

class cmp
{
    public:
        bool operator()(pi a, pi b)
        {
            return a.second > b.second;
        }
};
void Dijkstra(int src)
{
    priority_queue<pi, vector<pi>,cmp> pq;
    pq.push({src,0});
    dis[src] = 0;

    while(!pq.empty())
    {
        pi Pair = pq.top();
        pq.pop();
        ll node = Pair.first;
        ll cost = Pair.second;
        
        for(pi child : adj[node])
        {
            ll childNode = child.first;
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
    while(e--)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    for(int i=1; i<=n; i++)
    {
        dis[i] = 1e18;
        parent[i] = -1;
    }

    Dijkstra(1);

    if(dis[n] != 1e18)
    {
        ll x = n;
        vector<ll> v;
        while(x != -1)
        {
            v.push_back(x);
            x = parent[x];
        }
        reverse(v.begin(),v.end());
        for(ll val : v)
        {
            cout<<val<<" ";
        }
    }
    else cout<<"-1"<<endl;
    return 0;
}