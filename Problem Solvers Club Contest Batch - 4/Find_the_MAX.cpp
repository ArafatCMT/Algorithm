#include<bits/stdc++.h>
using namespace std;

class cmp
{
    public:
        bool operator()(pair<int,int> a, pair<int,int> b)
        {
            if(a.second == b.second)
            {
                return a.first < b.first;
            }
            else
            {
                return a.second < b.second;
            }
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    priority_queue< pair<int,int>, vector<pair<int,int>>,cmp> pq;
    map <int,int> mp;

    int Q;
    cin>> Q;

    while (Q--)
    {
        int x;
        cin>> x;

        if(x == 1)
        {
            int val;
            cin>> val;

            pq.push({val,mp[val]++});
        }
        else
        {
            if(pq.empty())
            {
                cout<<"empty"<<"\n";
            }
            else
            {
                int val = pq.top().first;

                if(mp[val] == 0)
                {
                    pq.pop();

                    if(pq.empty())
                    {
                        cout<<"empty"<<"\n";
                        continue;
                    }
                    val = pq.top().first;
                }

                pq.pop();
                mp[val] = 0;
                cout<< val <<"\n";

                while (!pq.empty())
                {
                    if(val == pq.top().first)
                    {
                        pq.pop();
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    
    return 0;
}