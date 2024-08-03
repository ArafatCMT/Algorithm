#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    bool flag = false;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == 1)
            {
                cout<<j;
            }
            else if(i == n || j == n)
            {
                cout<<n;
            }
            else if(flag == false)
            {
                cout<<i;
                flag = true;
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
        flag = false;
    }
    return 0;
}