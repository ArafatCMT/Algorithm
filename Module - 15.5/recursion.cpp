#include<bits/stdc++.h>
using namespace std;

bool Recursion(int *arr, int i, int n)
{
    //base case
    if(i == n) return true;
    if(arr[i] < arr[i+1])
    {
        return Recursion(arr,i+1,n);
    }
    else 
    {
        return false;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    bool flag = true;
    flag = Recursion(arr,0,n);
    (flag) ? cout<<"Sorted"<<endl : cout<<"Unsorted"<<endl;
    return 0;
}