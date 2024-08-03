#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);
    
    cout<< arr[0] + arr[1]<<endl;
    return 0;
}