#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char mat[N][N];
bool vis[N][N];
int n,m;
int cnt;
vector <pair<int,int>> d = {{0,1}, {0,-1}, {-1,0}, {1,0}};

bool isValid(int i, int j)
{
    return ((i>=0 && i<n && j>=0 && j<m) && !vis[i][j] && mat[i][j] == '.');
}

void dfs(int si, int sj)
{
    cnt++;
    vis[si][sj] = true;
    for(int i=0; i<4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(isValid(ci,cj))
        {
            dfs(ci,cj);
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
            vis[i][j] = false;
        }
    }

    int ans = INT_MAX;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!vis[i][j] && mat[i][j] == '.')
            {
                cnt = 0;
                dfs(i,j);
                ans = min(ans,cnt);
            }
        }
    }
    
    (ans != INT_MAX) ? cout<< ans <<endl : cout<< "-1" <<endl; 

    return 0;
}