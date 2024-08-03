#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> adj[n];
    while(e--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    for(int i=0; i<n; i++)
    {
        cout<<i<<" -> ";
        for(pair<int,int> child : adj[i])
        {
            cout<<"{"<<child.first<<","<<child.second<<"}"<<" ";
        }
        cout<<endl;
    }
    return 0;
}