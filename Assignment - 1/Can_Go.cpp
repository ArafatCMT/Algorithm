#include<bits/stdc++.h>
using namespace std;

char mat [1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int i, int j, int n, int m)
{
    return (i < 0 || i >= n || j < 0 || j >= m);
}

bool bfs(int sr, int sc, int n, int m)
{
    queue <pair<int,int>> q;
    q.push({sr,sc});
    vis[sr][sc] = true;

    while (!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;
        for(int i=0; i<4; i++)
        {
            int ci = r + v[i].first;
            int cj = c + v[i].second;
            if(valid(ci,cj,n,m) == false && mat[ci][cj] == 'B')
            {
                return true;
            }
            else
            {
                if(valid(ci,cj,n,m) == false && vis[ci][cj] == false && mat[ci][cj] != '#')
                {
                    q.push({ci,cj});
                    vis[ci][cj] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int n , m;
    cin>> n >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>mat[i][j];
        }
    }
    bool flag;
    memset(vis,false,sizeof(vis));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mat[i][j] == 'A')
            {
                flag = bfs(i,j,n,m);
                (flag) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
                break;
            }
        }
    }
    return 0;
}