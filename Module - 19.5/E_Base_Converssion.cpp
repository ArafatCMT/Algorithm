#include<bits/stdc++.h>
using namespace std;
void base_conversion(int n)
{
    if(n == 0) return;
    int rem = n % 2;
    base_conversion(n/2);
    cout<<rem;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        base_conversion(n);
        cout<<endl;
    }
    
    return 0;
}