#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
char mat[N][N];
bool vis[N][N];
int n, m, si, sj, di, dj;
map< pair<int,int>, pair<int,int>> mp;
class Person
{
    public:
        int r,c;
        char nm;

        Person(int r, int c, char nm)
        {
            this->r = r;
            this->c = c;
            this->nm = nm;
        }
};
queue <Person> q;
vector <pair<int,int>> d = {{0,1}, {0,-1}, {-1,0}, {1,0}};

bool is_valid(int i, int j)
{
    return (i>=0 && i<n && j>=0 && j<m) && mat[i][j] != '#';
}
void bfs()
{
    while (!q.empty())
    {

        Person parent = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            int ci = parent.r + d[i].first;
            int cj = parent.c + d[i].second;

            if(is_valid(ci,cj) && !vis[ci][cj])
            {
                q.push(Person(ci,cj,parent.nm));
                vis[ci][cj] = true;
                mat[ci][cj] = parent.nm;
                if(parent.nm == 'A')
                {
                    mp[{ci,cj}] = {parent.r, parent.c};
                }
            }
        }
    }
}
bool is_corner(int i, int j)
{
    return (i == 0 || i == n-1 || j == 0 || j == m-1);
}
bool Cheack()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(is_corner(i,j) && mat[i][j] == 'A')
            {
                di = i;
                dj = j;
                return true;
            }
        }
    }
    return false;
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
            if(mat[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if(mat[i][j] == 'M')
            {
                q.push(Person(i,j,'M'));
                vis[i][j] = true;
            }
            

        }
    }
    q.push(Person(si,sj,'A'));
    vis[si][sj] = true;
    bfs();
    
    if(!Cheack())
    {
        cout<<"NO"<<endl;
    }
    else 
    {
        vector <char> v;
        pair<int,int> x = {di,dj};

        while(x.first != si || x.second != sj)
        {
            pair<int,int> par = mp[{x.first,x.second}];

            //right er jonno
            if((par.first + 0) == x.first && (par.second + 1) == x.second)
            {
                v.push_back('R');
            }

            //left er jonno
            else if((par.first + 0) == x.first && (par.second - 1) == x.second)
            {
                v.push_back('L');
            }

            //up er jonno
            else if((par.first - 1) == x.first && (par.second + 0) == x.second)
            {
                v.push_back('U');
            }
            //dwon er jonno
            else if((par.first + 1) == x.first && (par.second + 0) == x.second)
            {
                v.push_back('D');
            }
            x = mp[{x.first,x.second}];
        }
        reverse(v.begin(),v.end());
        cout<<"YES"<<endl;
        cout<<v.size()<<endl;
        for(char c : v) cout<<c;
    }
    
    return 0;
}