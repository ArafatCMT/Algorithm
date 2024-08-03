#include<bits/stdc++.h>
using namespace std;

const int N = 1050;
bool vis[N][N];
pair<int,int> par[N][N];
int level[N][N];
char mat[N][N];
bool flag = false;
vector <char> ans;

vector<pair<int,int>> d = {{0,1}, {0,-1}, {-1,0}, {1,0}};

int n, m;

bool valid(int i, int j)
{
    return (i>=0 && i<n && j>=0 && j<m);
}

void bfs(int sr, int sc)
{
    queue <pair<int,int>> q;
    q.push({sr,sc});
    vis[sr][sc] = true;
    level[sr][sc] = 0;

    while(!q.empty())
    {
        pair<int,int> Pair = q.front();
        q.pop();
        int r = Pair.first;
        int c = Pair.second;

        for(int i=0; i<4; i++)
        {
            int a = d[i].first;
            int b = d[i].second;
            int ci = r + d[i].first;
            int cj = c + d[i].second;
            if(mat[ci][cj] == 'B') flag = true;
            if(valid(ci,cj) && !vis[ci][cj] && mat[ci][cj] != '#' && flag == false)
            {
                if(a == 0 && b == 1){
                    ans.push_back('R');
                }
                else if(a== 0 && b == -1){
                    ans.push_back('L');
                }
                else if(a == -1 && b == 0){
                    ans.push_back('U');
                }
                else if(a== 1 && b == 0){
                    ans.push_back('D');
                }

                q.push({ci,cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[r][c] + 1;
                

            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>mat[i][j];
            vis[i][j] = false;
            level[i][j] = -1;
        }
    }
    int Di, Dj;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(!vis[i][j] && mat[i][j] == 'A')
            {
                // sr = i;
                // sc = j;
                bfs(i,j);
            }
            if(mat[i][j] == 'B')
            {
                Di = i;
                Dj = j;
            }
        }
    }
    if(flag == true)
    {
        cout<<"YES"<<endl;
        cout<<level[Di][Dj]<<endl;
        for(char c : ans) cout<<c;
    }
    return 0;
}