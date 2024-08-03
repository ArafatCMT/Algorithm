#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int dp[N];
int solution(int arr[], int n, int i)
{
    if(i >= n) return 0;
    if(dp[i] != -1) return dp[i];
    int x = solution(arr, n, i+2) + arr[i];
    int y = solution(arr, n, i+1);
    return dp[i] = max(x,y);
}
int main()
{
    int t;
    cin>>t;
    int cs = 1;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            dp[i] = -1;
        }
        
        cout<<"Case "<< cs++ <<": "<< solution(arr, n, 0)<<endl;
    }
    return 0;
}