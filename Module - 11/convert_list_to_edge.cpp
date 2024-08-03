#include<bits/stdc++.h>
using namespace std;
class Edge
	{
	  public:
	    int u,v,c;
	    Edge(int u, int v, int c)
	    {
	        this->u = u;
	        this->v = v;
	        this->c = c;
	        
	    }
	};
	bool cmp(Edge a, Edge b)
	{
	    return a.c < b.c;
	}
int main()
{
    vector<vector<int>> v[3] = {{{0 ,1 ,5}}, {{1, 2 ,3}}, {{0, 2, 1}}};
    vector<Edge> e;
    for(int i=0; i<3; i++)
    {
        for(vector<int> a:v[i])
    {
        e.push_back(Edge(a[0],a[1],a[2]));
    }
    }
    sort(e.begin(),e.end(),cmp);
    for(Edge a:e)
    {
        cout<<a.u<<" "<<a.v<<" "<<a.c<<endl;
    }
    return 0;
}
