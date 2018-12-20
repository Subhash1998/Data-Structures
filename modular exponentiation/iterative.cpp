#include <bits/stdc++.h>
using namespace std;

long power(long x,long n,long p)
{
    long res=1;
    
    x=x%p;
    while(n>0)
    {
        //if n is odd number
        if(n&1)
            res=(res*x)%p;
        
        //divide n by 2 for log2(n) approach
        n=n>>1;
        x=(x*x)%p;
    }
    return res;
}

int main()
{
    long x,n,p,ans;
    cin>>x>>n>>p;
    ans=power(x,n,p);
    cout<<ans;
    return 0;
}

