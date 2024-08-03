#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int outer_space = n-1;
    int star = n*2;
    int inner_space = 4;

    for(int i=1; i<n*2; i++)
    {
        //outer space
        for(int j=1; j<=outer_space; j++)
        {
            cout<<" ";
        }

        //left side star printing loop
        for(int k=1; k<=star/2; k++)
        {
            cout<<"*";
        }

        if(i != 1 && i != (2 * n) - 1)
        {
            //inner space
            for(int j=1; j<=inner_space; j++)
            {
                cout<<" ";
            }
        }

        //right side star printing loop
        for(int k=1; k<=star/2; k++)
        {
            cout<<"*";
        }

        if(i < n)
        {
            outer_space--;
            star -= 2;

            if(i != 1)
            {
                inner_space += 4;
            }
        }
        else
        {
            outer_space++;
            star += 2;
            inner_space -= 4;
        }
        cout<<endl;
    }
    return 0;
}