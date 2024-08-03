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
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            pq.push({arr[i],i});
        }

        pair<int,int> x = pq.top();
        pq.pop();

        pair<int,int> y = pq.top();
        pq.pop();
        
        if(x.second < y.second)
        {
            cout<<x.second<<" "<<y.second<<endl;
        }
        else
        {
            cout<<y.second<<" "<<x.second<<endl;
        }
    }
    
    return 0;
}