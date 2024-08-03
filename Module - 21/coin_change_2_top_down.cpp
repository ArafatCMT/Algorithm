#include<bits/stdc++.h>
using namespace std;
int coin_change_2(int n, int s, int arr[])
{
    if(n == 0)
    {
        if(s == 0) return 0;
        else return INT_MAX - 1;
    }
    if(arr[n-1] <= s)
    {
        int op1 = coin_change_2(n, s - arr[n-1], arr) + 1;
        int op2 = coin_change_2(n-1, s, arr);
        return min(op1,op2);
    }
    else
    {
        return coin_change_2(n-1, s, arr);
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
    cout<<coin_change_2(n, s, arr)<<endl;
    return 0;
}