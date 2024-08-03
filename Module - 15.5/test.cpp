#include<bits/stdc++.h>
#define pr pair<int,int>
using namespace std;
const int N = 1005;
int dis[N];
vector<pair<int,int>> adj[N];

class cmp
{
    public:
    bool operator()(pair<int,int> a, pair<int,int>b)
    {
        return a.second > b.second;
    }
};
void Dijkstra(int src)
{
    priority_queue<pair<int,int> , vector<pair<int,int>> , cmp>pq;
    pq.push({src,0});
    dis[src] = 0;

    while (!pq.empty())
    {
        
    }
    
}

int main()
{
    int n,e;
    cin>>n>>e;
    
    while (e--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }
    
    return 0;
}