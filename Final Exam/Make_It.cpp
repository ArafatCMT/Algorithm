#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dp[N];
bool make_it(int n, int v)
{
    //base case
    if(v == n) return true;

    if(v > n) return false;

    if(dp[v] != -1) return dp[v];

    return dp[v] = make_it(n, v + 3) || make_it(n, v * 2);
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            dp[i] = -1;
        }
        (make_it(n,1)) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
    
    return 0;
}