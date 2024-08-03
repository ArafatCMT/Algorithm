class Solution {
public:
    int cnt = 0;
    bool vis[105][105];
    vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};

    bool valid(int row, int col, int i, int j)
    {
        return ((i >= 1 && i <= row - 2) && (j >= 1 && j <= col - 2));
    }
    bool bfs(vector<vector<int>> grid, int row, int col, int sr, int sc)
    {
        bool flag = false;

        queue <pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = true;

        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            
            int r = p.first;
            int c = p.second;

            if(r == 1)
            {
                if(grid[r-1][c] == 0)
                {
                    flag = true;
                }
            }
            else if(r == row - 2)
            {
                if(grid[r+1][c] == 0)
                {
                    flag = true;
                }
            }
            else if(c == 1)
            {
                if(grid[r][c-1] == 0)
                {
                    flag = true;
                }
            }
            else if(c == col - 2)
            {
                if(grid[r][c+1] == 0)
                {
                    flag = true;
                }
            }

            for(int  i=0; i<4; i++)
            {
                int ci = r + v[i].first;
                int cj = c + v[i].second;
                
                if(valid(row,col,ci,cj) == true && vis[ci][cj] == false && grid[ci][cj] == 0)
                {
                    q.push({ci,cj});
                    vis[ci][cj] = true;

                    if(ci == 1)
                    {
                        if(grid[ci-1][cj] == 0)
                        {
                            flag = true;
                        }
                    }
                    else if(ci == row - 2)
                    {
                        if(grid[ci+1][cj] == 0)
                        {
                            flag = true;
                        }
                    }
                    else if(cj == 1)
                    {
                        if(grid[ci][cj-1] == 0)
                        {
                            flag = true;
                        }
                    }
                    else if(cj == col - 2)
                    {
                        if(grid[ci][cj+1] == 0)
                        {
                            flag = true;
                        }
                    }
                }
            }
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        memset(vis,false,sizeof(vis));

        for(int i=1; i<row-1; i++)
        {
            for(int j=1; j<col-1; j++)
            {
                if(vis[i][j] == false && grid[i][j] == 0)
                {
                    bool flag = bfs(grid, row, col, i, j);
                    
                    if(flag == false)
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};