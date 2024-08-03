#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;

        string s;
        cin>>s;

        vector <char> open;
        vector <char> close;

        for(char ch : s)
        {
            if(ch == '(')
            {
                open.push_back(ch);
            }
            else
            {
                close.push_back(ch);
            }
        }

        if(open.size() == close.size())
        {
            cout<<"Possible"<<endl;
        }
        else
        {
            cout<<"Impossible"<<endl;
        }
    }
    return 0;
}