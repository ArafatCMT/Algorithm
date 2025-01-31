#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 1e6 + 5;
ll dp[N];
ll fibo(int n)
{
    if(n == 1 || n == 0)
    {
        return n;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }
    ll ans = fibo(n-1) + fibo(n-2);
    dp[n] = ans;
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<fibo(n)<<endl;
    return 0;
}