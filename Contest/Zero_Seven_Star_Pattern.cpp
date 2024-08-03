#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == 1)
            {
                if(j == 1 || j == n) cout<<"*";
                else cout<<"7";
            }
            else if(i == n)
            {
                if(j == 1 || j == n) cout<<"*";
                else cout<<"0";
            }
            else if(i == j || j == n-(i-1))
            {
                cout<<"*";
            }
            else if(j < i)
            {
                cout<<"0";
            }
            else
            {
                cout<<"7";
            }
        }
        cout<<endl;
    }
    return 0;
}