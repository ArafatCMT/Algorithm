#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }

        for(int i=0; i<n-1; i++)
        {
            int mx = arr[i];
            for(int j=i+1; j<n; j++)
            {
                mx = max(mx,arr[j]);
                cout<<mx<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}