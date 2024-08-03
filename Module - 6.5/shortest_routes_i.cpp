#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 5;
ll dis[N];
vector <pair<int,ll>> adj [N];
class cmp
{
    public:
        bool operator()(pair<int, ll> a, pair<int, ll> b)
        {
            return a.second > b.second;
        }
};
void Dijkstra(int src)
{
    priority_queue< pair<int,ll>, vector<pair<int,ll>>, cmp > pq;
    pq.push({src,0});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair <int,ll> Pair = pq.top();
        pq.pop();
        int node = Pair.first;
        int cost = Pair.second;

        for(pair<int,ll> child : adj[node])
        {
            int childNode = child.first;
            int childCost = child.second;

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
    while (e--)
    {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    for(int i=1; i<=n; i++)
    {
        dis[i] = 1e18;;
    }
    Dijkstra(1);
    for(int i=1; i<=n; i++)
    {
        cout<<dis[i]<<" ";
    }
    return 0;
}