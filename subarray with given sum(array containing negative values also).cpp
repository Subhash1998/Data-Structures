#include <bits/stdc++.h>
using namespace std;

int subarray(int a[],int n,int k)
{
    int i,sum=0,ans=0;
    unordered_map<int,int > m;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        
        if(sum==k)
            ans++;
        
        if(m.find(sum-k)!=m.end())
            ans+=m[sum-k];
        
        m[sum]++;
    }
    return ans;
}

int main()
{
    int a[] = { 10, -5 , 10 , 5, -10, -10 };
    int n = sizeof(a)/sizeof(a[0]);
    int k = -5;
    cout<<subarray(a,n,k);
    return 0;
}
