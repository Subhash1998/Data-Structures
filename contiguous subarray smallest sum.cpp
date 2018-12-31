#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[]={5,2,-3, 6,-4,-1,-1},minm=INT_MAX,currsum=INT_MAX;
    int n=7;
    for(int i=0;i<n;i++)
    {
        if(currsum>0)
            currsum=a[i];
        else
            currsum+=a[i];
            
        minm= min(currsum,minm);
    }
    cout<<minm;
    return 0;
}
