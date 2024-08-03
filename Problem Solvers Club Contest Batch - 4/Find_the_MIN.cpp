#include<bits/stdc++.h>
using namespace std;
const int N = 1e9 + 5;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin>> Q;
    
    set <int> st;

    while (Q--)
    {
        int x;
        cin>>x;

        if(x == 1)
        {
            int val;
            cin>>val;

            st.insert(val);
        }
        else
        {
            if(st.empty())
            {
                cout<< "empty" <<"\n";
            }
            else
            {
                auto it = st.begin();
                cout<< *it << "\n";

                st.erase(st.begin());
            }
        }
    }
    return 0;
}