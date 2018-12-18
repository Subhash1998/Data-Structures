#include <bits/stdc++.h>
using namespace std;

long power(long x,long n,long p)
{
    if(n==0)
        return 1;
    else if(n==1)
        return x;
    else
    {
        long r=power(x,n/2,p);
        if(n%2==0)  
            return ((r%p)*(r%p))%p;
        else    
            return ((r%p)*x*(r%p))%p; 
    }
}

int main()
{
    long x,n,p,ans;
    cin>>x>>n>>p;
    ans=power(x,n,p);
    cout<<ans;
    return 0;
}

