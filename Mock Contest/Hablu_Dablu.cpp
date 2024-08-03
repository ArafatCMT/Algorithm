#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, h;
    cin>> n >> h;
    int arr[n];
    int mx = INT_MIN;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        mx = max(arr[i],mx);
    }

    while(true)
    {
        mx = mx - 1;
        
        h = h - mx;

        if(h <= 0 || mx == 0)
        {
            break;
        } 
    }
    
    if(mx == 0 && h > 0)
    {
        cout<<"Hablu"<<endl;
    }
    else
    {
        cout<<"Dablu"<<endl;
    }
    return 0;
}