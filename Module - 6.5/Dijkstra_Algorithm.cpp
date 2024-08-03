#include<bits/stdc++.h>
using namespace std;

// const int N = 105;
vector<pair<int,int>> adj[105];
int dis[105];

class cmp
{
    public:
        bool operator()(pair<int,int> a, pair<int,int> b)
        {
            return a.second > b.second;
        }
};

void Dijkstra(int src)
{
    priority_queue< pair<int,int> , vector<pair<int,int>> , cmp >pq;
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
                //path relaxation
                dis[childNode] = cost + childCost;
                pq.push({childNode,dis[childNode]});
            }
        }
    }
}
int main()
{
    int n,s,f;
    cin>>n>>s>>f;
    int mat[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>mat[i][j];
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i !=j && mat[i][j] != -1)
            {
                adj[i].push_back({j,mat[i][j]});
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        dis[i] = INT_MAX;
    }

    Dijkstra(s);

    if(dis[f] == INT_MAX)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<dis[f]<<endl;
    }
    return 0;
}