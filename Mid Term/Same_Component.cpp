#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char mat[N][N];
bool vis[N][N];
vector <pair<int, int>> v = {{0,1}, {0,-1}, {-1,0}, {1,0}};
int n,m;

bool valid(int i, int j)
{
    return ((i>=0 && i<n) && (j>=0 && j<m));
}
void bfs(int sr, int sc)
{
    queue <pair<int, int>> q;
    q.push({sr,sc});
    vis[sr][sc] = true;

    while(!q.empty())
    {
        pair<int,int> Pair = q.front();
        q.pop();

        int r = Pair.first;
        int c = Pair.second;

        for(int i=0; i<4; i++)
        {
            int ci = r + v[i].first;
            int cj = c + v[i].second;

            if(valid(ci,cj) == true && vis[ci][cj] == false && mat[ci][cj] !='-')
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> mat[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    int sr, sc, di, dj;
    cin >> sr >> sc >> di >> dj;
    bfs(sr,sc);
    
    if(vis[di][dj] == true) cout<<"YES";
    else cout<<"NO";
    return 0;
}