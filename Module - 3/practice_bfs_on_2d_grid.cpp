#include<bits/stdc++.h>
using namespace std;

char mat [20][20];
bool vis[20][20];
int dis[20][20];
vector <pair<int,int>> v = {{-1,-1},{-1,1},{1,-1},{1,1}};
// vector <pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};
int row,col;

bool valid(int i, int j)
{
    if(i < 0 || i >= row || j < 0 || j >= col) return false;
    else return true;
}
void bfs(int si, int sj)
{
    queue <pair<int,int>> q;
    q.push(make_pair(si,sj));
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        int a = p.first;
        int b = p.second;
        for(int i=0; i<4; i++)
        {
            int ci = a + v[i].first;
            int cj = b + v[i].second;
            if(valid(ci,cj) == true && vis[ci][cj] == false)
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
    
}
int main()
{
    cin>>row>>col;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin>>mat[i][j];
        }
    }
    int si,sj;
    cin>>si>>sj;
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    bfs(si,sj);
    cout<<dis[3][3];
    return 0;
}