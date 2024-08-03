#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1e6 + 5;
vector <pair<int,ll>> adj[N];
ll dis[N];

class cmp
{
    public:
        bool operator()(pair<int,ll> a, pair<int,ll> b)
        {
            return a.second > b.second;
        }
};
void Dijkstra(int src)
{
    priority_queue< pair<int, ll> , vector<pair<int,ll>>, cmp > pq;
    pq.push({src,0});

    while (!pq.empty())
    {
        pair<int, ll> Pair = pq.top();
        pq.pop();
        int node = Pair.first;
        ll cost = Pair.second;

        for(pair<int,ll> child : adj[node])
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
    while (e--)
    {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    for(int i=1; i<=n; i++)
    {
        dis[i] = INT_MAX;
    }
    int src;
    cin>>src;
    dis[src] = 0;
    Dijkstra(src);
    int test;
    cin>>test;
    while (test--)
    {
        int d,dw;
        cin>>d>>dw;
        if(dis[d] <= dw) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    
    return 0;
}