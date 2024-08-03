// Dijkstra Algorithm Optimize Version : Time Complexity - O ((V+E) log V)
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dis[N];
vector<pair<int,int>> adj[N];

class cmp
{
    public:
        bool operator ()(pair<int,int> a, pair<int,int> b)
        {
            return a.second > b.second;
        }
};
void Dijkstra(int src)
{
    priority_queue < pair<int,int> , vector<pair<int,int>> , cmp > pq;
    pq.push({src,0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int,int> Pair = pq.top();
        pq.pop();
        int node = Pair.first;
        int cost = Pair.second;
        
        for(pair<int,int> child : adj[node])
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
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }
    Dijkstra(0);
    for(int i=0; i<n; i++)
    {
            cout<<i<<" -> "<<dis[i]<<endl;
    }
    return 0;
}