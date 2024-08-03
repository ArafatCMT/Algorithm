#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n;
    cin>> n;
    ll arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    ll mx = INT_MIN;

    for(int i=0; i<n; i++)
    {
        if(arr[i] % 2 == 0)
        {
            mx = max(mx, arr[i]);
        }
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            ll sum = arr[i] + arr[j];

            if(sum % 2 == 0)
            {
                mx = max(mx, sum);
            }
        }
    }

    cout<<mx<<endl;

    return 0;
}