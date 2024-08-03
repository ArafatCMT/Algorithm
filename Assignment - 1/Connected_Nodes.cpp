#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector <int> adj[N];

void dfs(int src , vector <int> &v)
{
    for(int child : adj[src])
    {
        v.push_back(child);
    }
}
int main()
{
    int node , edge;
    cin >> node >> edge;
    while(edge--)
    {
        int u , v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int Q;
    cin>> Q;
    while (Q--)
    {
        int src;
        cin >> src;
        vector <int> v;
        dfs(src,v);
        sort(v.begin(),v.end(),greater<int>());
        if(v.empty()) 
        {
            cout<<"-1"<<endl;
        }
        else
        {
            for(int val:v)
            {
                cout<<val<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}