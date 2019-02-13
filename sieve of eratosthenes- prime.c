#include <bits/stdc++.h>
using namespace std;

void sieve(int n)
{
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    int p,i;
    for(p=2;p*p<=n;p++)
    {
        if(prime[p])
        {
            for(i=p*p;i<=n;i+=p)
                prime[i]=false;
        }
    }
    for(i=2;i<=n;i++)
    {
        if(prime[i])
            cout<<i<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    sieve(n);
    return 0;
}
