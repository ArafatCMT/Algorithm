#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mat[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>mat[i][j];
        }
    }
    vector<pair<int,int>> edge;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mat[i][j] == 1 && i != j)
            {
                edge.push_back({i,j});
            }
        }
    }
    for(pair<int,int> ed : edge)
    {
        cout<<ed.first<<" "<<ed.second<<endl;
    }
    return 0;
}