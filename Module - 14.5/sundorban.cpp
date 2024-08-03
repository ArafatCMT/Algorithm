#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;

const int N = 35;
char mat[N][N];
bool vis[N][N];
int dis[N][N];
int sx,sy,dx,dy,n;
vector <pi> d = {{0,1}, {0,-1}, {-1,0}, {1,0}}; 

bool isValid(int ci, int cj)
{
    return ((ci>=0 && ci<n && cj>=0 && cj<n) && !vis[ci][cj] && mat[ci][cj] != 'T');
}
void bfs(int sr, int sc)
{
    queue <pi> q;
    q.push({sr,sc});
    vis[sr][sc] = true;
    dis[sr][sc] = 0;

    while(!q.empty())
    {
        pi Pair = q.front();
        q.pop();
        int r = Pair.first;
        int c = Pair.second;
        for(int i=0; i<4; i++)
        {
            int ci = r + d[i].first;
            int cj = c + d[i].second;

            if(isValid(ci,cj))
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[r][c] + 1;
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>mat[i][j];
            if(mat[i][j] == 'S') 
            {
                sx = i;
                sy = j;
            }
            if(mat[i][j] == 'E') 
            {
                dx = i;
                dy = j;
            }
            vis[i][j] = false;
            dis[i][j] = -1;
        }
    }
    bfs(sx,sy);
    cout<<dis[dx][dy];
    return 0;
}