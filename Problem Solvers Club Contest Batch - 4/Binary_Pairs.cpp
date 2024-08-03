#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>> t;
    while (t--)
    {
        int n;
        cin>> n;

        string s;
        cin>>s;

        int sz = s.size();
        int cnt = 0;

        for(int  i=0; i<sz-1; i++)
        {
            if((s[i] == '1' && s[i+1] == '0') || (s[i] == '0' && s[i+1] == '1'))
            {
                cnt++;
            }
        }

        cout<< cnt << endl;
    }
    
    return 0;
}