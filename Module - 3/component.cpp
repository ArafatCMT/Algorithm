#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool vis[N];
vector<int> v[N];
void dfs(int src)
{
    cout<<src<<endl;
    vis[src] = true;
    for(int child:v[src])
    {
        if(!vis[child]) dfs(child);
    }

}
int main()
{
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0; i<n; i++)
    {
        if(vis[i] == false)
        {
            dfs(i);
        }
    }
    return 0;
}