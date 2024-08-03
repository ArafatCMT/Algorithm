#include<bits/stdc++.h>
using namespace std;
class myStack
{
    public:
        list<int> l;

        void push(int val)
        {
            l.push_back(val);
        }
        void pop()
        {
            l.pop_back();
        }
        int top()
        {
            return l.back();
        }
        int size()
        {
            return l.size();
        }
        bool empty()
        {
            return l.empty();
        }
};
int main()
{
    int n;
    cin>>n;
    myStack st;
    while (n--)
    {
        int val;
        cin>>val;
        st.push(val);
    }
    while (!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    
    return 0;
}