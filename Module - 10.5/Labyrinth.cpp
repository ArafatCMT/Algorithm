#include<bits/stdc++.h>
using namespace std;

const int N = 1050;
bool vis[N][N];
pair<int,int> par[N][N];
int level[N][N];
char mat[N][N];

vector <char> direction;

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
            int ci = r + d[i].first;
            int cj = c + d[i].second;

            if(valid(ci,cj) && !vis[ci][cj] && mat[ci][cj] != '#')
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[r][c] + 1;
                par[ci][cj] = {r,c};

            }
        }
    }
}
void path_direction(pair<int,int>src,pair<int,int>dst)
{
    pair<int,int>selected_node = dst;
    while(true)
    {
        int x = selected_node.first;
        int y = selected_node.second;
        int x1 = par[x][y].first;
        int y1 = par[x][y].second;
        if(x>x1 && y==y1)
        {
            direction.push_back('D');
        }
        else if(x<x1 && y==y1)
        {
            direction.push_back('U');
        }
        else if(y>y1 && x==x1)
        {
            direction.push_back('R');
        }
        else if(y<y1 && x==x1)
        {
            direction.push_back('L');
        }
        if(selected_node == src)
        {
            break;
        }
 
        selected_node = par[x][y];
    }
    reverse(direction.begin(),direction.end());
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>mat[i][j];
            par[i][j] = {-1,-1};
            vis[i][j] = false;
            level[i][j] = -1;
        }
    }

    pair<int,int> src;
    pair<int,int> dst;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mat[i][j] == 'A')
            {
                src = {i,j};
                bfs(i,j);
            }
            if(mat[i][j] == 'B')
            {
                dst = {i,j};
            }
        }
    }
    // cout<<dst.first<<" "<<dst.second<<endl;
    if(vis[dst.first][dst.second])
    {
        cout<<"YES"<<endl;
        cout<<level[dst.first][dst.second]<<endl;
        path_direction(src,dst);
        for(char c : direction) cout<<c;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    return 0;
}