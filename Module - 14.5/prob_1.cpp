#include<bits/stdc++.h>
using namespace std;

bool vis[35][35];
int dis[35][35];
char mat[35][35];
int si, sj, ri, rj, di, dj, n;
vector <pair<int,int>> d = {{0,1}, {0,-1}, {-1,0}, {1,0}};

bool isValid(int i, int j)
{
    return (i>=0 && i<n && j>=0 && j<n) && !vis[i][j] && mat[i][j] != 'O';
}
void bfs(int si, int sj)
{
    queue <pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while(!q.empty())
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
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>mat[i][j];
                vis[i][j] = false;
                dis[i][j] = -1;
                if(mat[i][j] == 'M')
                {
                    si = i;
                    sj = j;
                }
                if(mat[i][j] == 'R')
                {
                    ri = i;
                    rj = j;
                }
                if(mat[i][j] == 'D')
                {
                    di = i;
                    dj = j;
                }
            }
        }
        bfs(si,sj);
        if(dis[ri][rj] != -1)
        {
            int x = dis[ri][rj];
            memset(vis,false,sizeof(vis));
            bfs(ri,rj);

            if(dis[di][dj] != -1)
            {
                cout<< x+dis[di][dj]<<endl;
            }
            else
            {
                cout<<"-1"<<endl;
            }
        }
        else
        {
            cout<<"-1"<<endl;
        }
    }
    return 0;
}