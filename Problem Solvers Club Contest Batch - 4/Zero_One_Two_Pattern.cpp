#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>> n;
    int m = (2*n) - 1;
    int flag = 1;

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(j == i)
            {
                cout<<flag;
            }
            else if(j == m-i+1) 
            {
                cout<<flag;
            }
            else 
            {
                cout<<" ";
            }
        }

        if(flag == 1) 
        {
            flag = 2;
        }
        else if(flag == 2) 
        {
            flag = 0;
        }
        else if(flag == 0) 
        {
            flag = 1;
        }
        
        cout<<endl;
    }
    return 0;
}