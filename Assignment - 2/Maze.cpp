#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
const int N = 1e3 + 5;
char mat[N][N];
bool vis[N][N];
map <pi, pi> mp;
int n, m, si, sj, di, dj;
vector <pi> d = {{0,1}, {0,-1}, {-1,0}, {1,0}};

bool isValid(int i, int j)
{
    return ((i>=0 && i<n && j>=0 && j<m) && !vis[i][j] && mat[i][j] != '#');
}
void bfs(int si, int sj)
{
    queue <pi> q;
    q.push({si,sj});
    vis[si][sj] = true;

    while(!q.empty())
    {
        pi Parent = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            int ci = Parent.first + d[i].first;
            int cj = Parent.second + d[i].second;

            if(isValid(ci,cj))
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                mp[{ci,cj}] = {Parent.first, Parent.second};
            }
        }
    }

}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>mat[i][j];

            if(mat[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if(mat[i][j] == 'D')
            {
                di = i;
                dj = j;
            }

            vis[i][j] = false;
        }
    }
    bfs(si,sj);
    
    if(vis[di][dj])
    {
        pi x = mp[{di,dj}];
        
        while(x.first != si || x.second != sj)
        {
            mat[x.first][x.second] = 'X';
            x = mp[{x.first,x.second}];
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<mat[i][j];
            }
            cout<<endl;
        }
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<mat[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}