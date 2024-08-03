#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1005;
ll dis[N][N];
ll mat[N][N];
int n, m, si, sj, di, dj;
vector<pair<int,int>> d = {{-1,-1}, {-1,1}, {1,-1}, {1,1}};

class cmp
{
    public:
        bool operator()(pair<pair<int,int>,ll> a, pair<pair<int,int>,ll> b)
        {
            return a.second > b.second;
        }
};

bool is_valid(int ci, int cj)
{
    return ci >= 0 && ci < n && cj >= 0 && cj < m;
}
void Dijkstra(int si, int sj)
{
    priority_queue< pair<pair<int,int>,ll> , vector< pair< pair<int,int>,ll>>, cmp> pq;
    pq.push({{si,sj},0});
    dis[si][sj] = 0;

    while (!pq.empty())
    {
        pair<pair<int,int>,ll> par = pq.top();
        pq.pop();

        int r = par.first.first;
        int c = par.first.second;
        ll cost = par.second;

        for(int i=0; i<4; i++)
        {
            int ci = r + d[i].first;
            int cj = c + d[i].second;

            if(is_valid(ci,cj) && mat[ci][cj] != 0 && cost + mat[ci][cj] < dis[ci][cj])
            {
                if(si == ci && sj == cj)
                {
                    continue;
                }
                pq.push({{ci,cj},cost+mat[ci][cj]});
                dis[ci][cj] = cost + mat[ci][cj];
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    int cs = 1;
    
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>mat[i][j];

                if(mat[i][j] == -1)
                {
                    si = i;
                    sj = j;
                }

                if(mat[i][j] == -2)
                {
                    di = i;
                    dj = j;
                }

                dis[i][j] = 1e18;
            }
        }

        Dijkstra(si,sj);

        if(dis[di][dj] != 1e18)
        {
            cout<<"Case "<<cs++<<": "<< dis[di][dj]  <<endl;
        }
        else
        {
            cout<<"Case "<<cs++<<": "<<"Impossible"<<endl;
        }
    }
    return 0;
}