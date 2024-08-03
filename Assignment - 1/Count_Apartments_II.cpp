#include<bits/stdc++.h>
using namespace std;

char mat[1005][1005];
int vis[1005][1005] = {0};
vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};
int cnt = 0;

bool valid(int i, int j, int n, int m)
{
    return (i < 0 || i >= n || j < 0 || j >= m);
}

void bfs(int i, int j, int n, int m)
{
    queue <pair<int,int>> q;
    q.push({i,j});
    vis[i][j] = 1;
    cnt ++;

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

            if(valid(ci,cj,n,m) == false && vis[ci][cj] == 0 && mat[ci][cj] != '#')
            {
                q.push({ci,cj});
                vis[ci][cj] = 1;
                cnt++;
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
            cin >> mat[i][j];
        }
    }

    vector <int> v;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vis[i][j] == 0 && mat[i][j] != '#')
            {
                bfs(i,j,n,m);
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }

    if(v.empty())
    {
        cout<< cnt <<endl;
    }
    else
    {
        sort(v.begin(),v.end());

        for(int x : v)
        {
            cout<<x<<" ";
        }
    }
    return 0;
}