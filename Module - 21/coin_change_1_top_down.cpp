#include<bits/stdc++.h>
using namespace std;
map <pair<int,int>, int> dp;
int coin_change_1(int n, int s, int arr[])
{
    if(n == 0)
    {
        if(s == 0) return 1;
        else return 0;
    }

    // if(dp.count({n,s}) != 0) return dp[{n,s}];
    if(dp.find({n,s}) != dp.end()) return dp[{n,s}];

    if(arr[n-1] <= s)
    {
        int op1 = coin_change_1(n, s - arr[n-1], arr);
        int op2 = coin_change_1(n-1, s, arr);
        return dp[{n,s}] = op1 + op2;
    }
    else
    {
        return dp[{n,s}] = coin_change_1(n-1, s, arr);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int s;
    cin>>s;
    cout<<coin_change_1(n, s, arr)<<endl;
    return 0;
}