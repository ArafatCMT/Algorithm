#include<bits/stdc++.h>
#define ll long long int
using namespace std;

map<pair<int,int>, ll> dp;
ll s;
bool target_sum(ll arr[], ll n, ll target)
{
    if(n == -1)
    {
        return target == s;
    }

    if(dp.find({n,target}) != dp.end()) return dp[{n,target}];

    bool positive = target_sum(arr, n-1, target - arr[n]);
    bool negative = target_sum(arr, n-1, target + arr[n]);

    return dp[{n,target}] = positive || negative;
}
int main()
{
    ll n,target;
    cin>>n>>target;
    s = target;
    ll arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    if(target_sum(arr,n-2,arr[n-1]))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}