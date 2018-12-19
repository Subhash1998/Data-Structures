#include<bits/stdc++.h>
using namespace std;

long digitsum(long val)
{
    long sum=0;
    if(val<10)
        sum=val;
    while(val>=10)
    {
        sum=0;
        while(val>0)
        {
            sum+=val%10;
            val/=10;
        }
        val=sum;
    }
    return sum;
}

int main()
{
    long n,q,a[1000000],i;
    cin>>n>>q;
    for(i=0;i<n;i++)
    {
        long val;
        cin>>val;
        a[i]=digitsum(val);
    }
    sort(a,a+n);
    long pre[n];
    pre[0]=a[0];
    for(i=1;i<n;i++)
        pre[i]=a[i]+pre[i-1];
    while(q--)
    {
        long x,k;
        long sum=0;
        cin>>x>>k;
        if(x==2)
        {
            sum=pre[k-1];
        }
        else
        {
            if(k!=n)
                sum=pre[n-1]-pre[n-k-1];
            else
                sum=pre[n-1];
        }
        cout<<sum<<"\n";
    }
    return 0;
}
