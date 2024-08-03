#include<bits/stdc++.h>
using namespace std;

char mat[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int i, int j, int n, int m)
{
    return (i < 0 || i >= n || j < 0 || j >= m);
}

void bfs(int i, int j, int n, int m)
{
    queue <pair<int,int>> q;
    q.push({i,j});
    vis[i][j] = true;
    
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

            if(valid(ci,cj,n,m) == false && vis[ci][cj] == false && mat[ci][cj] != '#')
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
            }
        }
    }
}
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>mat[i][j];
        }
    }

    int cnt = 0;
    memset(vis,false,sizeof(vis));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vis[i][j] == false && mat[i][j] != '#')
            {
                bfs(i,j,n,m);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}