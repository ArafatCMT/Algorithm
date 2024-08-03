#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>> t;
    while (t--)
    {
        int n, k;
        cin>> n >> k;
        int arr[n];
        set <int> s;

        for(int i=0; i<n; i++)
        {
            cin>> arr[i];
            s.insert(arr[i]);
        }

        int cnt = n - s.size();

        for(auto it = s.begin(); it != s.end(); it++)
        {
            if(*it > n)
            {
                cnt++;
            }
        }

        (cnt <= k) ? cout<<"YES" <<"\n" : cout<<"NO" <<"\n";
        
    }
    
    return 0;
}