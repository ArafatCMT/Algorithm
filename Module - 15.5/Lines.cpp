#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
const int N = 50;
char mat[N][N];
bool vis[N][N];
pi parent[N][N];
int n , si, sj, di, dj;
vector <pi> d = {{0,1}, {0,-1}, {-1,0}, {1,0}};
bool isVaild(int ci, int cj)
{
    return (ci>=0 && ci<n && cj>=0 && cj<n);
}
void bfs(int si, int sj)
{
    queue <pi> q;
    q.push({si,sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pi Pair = q.front();
        q.pop();
        int r = Pair.first;
        int c = Pair.second;
        for(int i=0; i<4; i++)
        {
            int ci = r + d[i].first;
            int cj = c + d[i].second;

            if(isVaild(ci,cj) && !vis[ci][cj] && mat[ci][cj] != 'O')
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {r,c};
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
            if(mat[i][j] == 'X')
            {
                si = i;
                sj = j;
            }
            if(mat[i][j] == '@')
            {
                di = i;
                dj = j;
            }
            vis[i][j] = false;
            parent[i][j] = {-1,-1};
        }
    }

    bfs(si,sj);
    
    if(vis[di][dj])
    {
        mat[di][dj] = '@';

        pi x = parent[di][dj];
        
        while (x.first != -1 && x.second != -1)
        {
            mat[x.first][x.second] = '+';
            x = parent[x.first][x.second];
        }
        
        cout<<"Y"<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<mat[i][j];
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"N"<<endl;
    }
    return 0;
}