#include<bits/stdc++.h>
using namespace std;

char mat[20][20];
bool vis[20][20];
vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};
int row,col;

bool valid(int i, int j)
{
    if(i<0 || i>=row || j<0 || j>=col) return false;
    else return true;
    
}
void dfs(int si, int sj)
{
    cout<<si<<" "<<sj<<endl;
    vis[si][sj] = true;
    for(int i=0; i<4; i++)
    {
        int ci = si + v[i].first;
        int cj = sj + v[i].second;
        if(valid(ci,cj) == true && vis[ci][cj] == false)
        {
            dfs(ci,cj);
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
    dfs(si,sj);
    return 0;
}