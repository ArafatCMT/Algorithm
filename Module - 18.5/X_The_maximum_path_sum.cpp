#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 20;
ll mat[N][N];
ll n,m;
bool isValid(int i, int j)
{
    return i>=1 && i<=n && j>=1 && j<=m;
}
ll maximum_path_sum(ll n, ll m, ll i, ll j)
{
    if(!isValid(i,j)) return INT_MIN;
    if(i == n && j == m) return mat[n][m];

    ll x = maximum_path_sum(n, m, i+1, j)+ mat[i][j];
    ll y = maximum_path_sum(n, m, i, j+1)+ mat[i][j];
    return max(x,y)  ;   
}
int main()
{
    
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<maximum_path_sum(n,m,1,1)<<endl;
    return 0;
}