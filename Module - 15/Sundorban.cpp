#include<bits/stdc++.h>
using namespace std;
char mat[35][35];
bool vis[35][35];
int dis[35][35];
int n;
vector<pair<int,int> > d;
bool isValid(int ci, int cj)
{
    return ((ci>=0 && ci<n && cj>=0 && cj<n) && !vis[ci][cj] && mat[ci][cj] != 'T');
}
void bfs(int si, int sj)
{
    queue <pair<int,int> > q;
    q.push({si,sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pair<int,int> Pair = q.front();
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
    d.push_back({0,1});
    d.push_back({0,-1});
    d.push_back({-1,0});
    d.push_back({1,0});
    while(cin>>n)
    {
        int si,sj;
        int di,dj;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>mat[i][j];
                if(mat[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if(mat[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
                vis[i][j]  = false;
                dis[i][j] = -1;
            }
        }
        bfs(si,sj);
        cout<<dis[di][dj]<<endl;
    }
    return 0;
}