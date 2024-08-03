#include<bits/stdc++.h>
using namespace std;
int main()
{
    int Q;
    cin>>Q;
    priority_queue<int, vector<int>, greater<int>> odd;
    priority_queue<int, vector<int>, greater<int>> even;
    while (Q--)
    {
       int cmnd;
       cin>> cmnd;
       
       if(cmnd == 1)
       {
            int val;
            cin>>val;

            if(val % 2 == 0)
            {
                even.push(val);
            }
            else
            {
                odd.push(val);
            }
       }
       // even number print and remove
       else if(cmnd == 2)
       {
            if(even.empty())
            {
                cout<<"empty"<<endl;
            }
            else
            {
                cout<<even.top()<<endl;
                even.pop();
            }
       }
       else if(cmnd == 3)
       {
            if(odd.empty())
            {
                cout<<"empty"<<endl;
            }
            else
            {
                cout<<odd.top()<<endl;
                odd.pop();
            }
       }
    }
    return 0;
}