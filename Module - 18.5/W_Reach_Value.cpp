#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int Reach_value(ll n, ll val)
{
    if(val == n) return 1;
    if(val > n) return 0;
    int x = Reach_value(n, val*10);
    int y = Reach_value(n, val*20);
    return max(x,y);
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        int val = Reach_value(n, 1);
        (val == 1) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
    return 0;
}