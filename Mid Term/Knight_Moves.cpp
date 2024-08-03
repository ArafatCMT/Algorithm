#include<bits/stdc++.h>
using namespace std;

int dis [105][105];
bool vis [105][105];
vector < pair<int, int>> v = {{-1,2}, {1,2}, {-1,-2}, {1,-2}, {-2,-1}, {-2,1}, {2,-1}, {2,1}};

bool valid(int i, int j, int n, int m)
{
    return ((i >= 0 && i < n) && (j >=0 && j < m));
}
void bfs(int sr, int sc, int n, int m)
{
    queue < pair<int, int>> q;
    q.push({sr,sc});
    vis[sr][sc] = true;
    dis [sr][sc] = 0;

    while(!q.empty())
    {
        pair<int, int> Pair = q.front();
        q.pop();

        int r = Pair.first;
        int c = Pair.second;

        for(int i=0; i<8; i++)
        {
            int ci = r + v[i].first;
            int cj = c + v[i].second;

            if(valid(ci,cj,n,m) && !vis[ci][cj])
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
    int test;
    cin>>test;
    while (test--)
    {
        int n, m;
        cin>> n >> m;
        int mat[n][m];

        int Ki, Kj;
        cin>> Ki >> Kj;

        int Qi, Qj;
        cin>> Qi >> Qj;
          
        memset(dis, -1, sizeof(dis));
        memset(vis, false, sizeof(vis));

        bfs(Ki,Kj,n,m);

        cout<< dis[Qi][Qj] <<endl;
    }
    
    
    return 0;
}