// Dijkstra Algorithm Naive Version : Time Complexity - O (E * V)
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dis[N];
vector<pair<int,int>> adj[N];

void Dijkstra(int src)
{
    queue <pair<int,int>> q;
    q.push ({src,0});
    dis[src] = 0;
    while(!q.empty())
    {
        pair<int,int> Pair = q.front();
        q.pop();
        int node = Pair.first;
        int cost = Pair.second;
        for(pair<int,int> child : adj[node])
        {
            int childNode = child.first;
            int childCost = child.second;

            if(cost + childCost < dis[childNode])
            {
                //path relax
                dis[childNode] = cost + childCost;
                q.push({childNode,dis[childNode]});
            }
        }
    }
}
int main()
{
    int n,e;
    cin>> n>>e;
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