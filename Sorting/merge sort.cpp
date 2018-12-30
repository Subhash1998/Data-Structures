#include <bits/stdc++.h>
using namespace std;

void merge(int a[],int l,int mid,int r)
{
    int n1,n2,i,j;
    n1=mid-l+1;
    n2=r-mid;
    int a1[n1],a2[n2];
    
    for(i=0;i<n1;i++)
        a1[i]=a[l+i];
    for(i=0;i<n2;i++)
        a2[i]=a[mid+1+i];
    
    int k=l;
    i=0,j=0;
    
    while(i<n1 && j<n2)
    {
        if(a1[i]<=a2[j])
        {
            a[k++]=a1[i++];
        }
        else
        {
            a[k++]=a2[j++];
        }
    }
    
    //after above loop either i>=n1 or j>=n2
    
    for(int p=i;p<n1;p++)
    {
        a[k++]=a1[p];
    }
    for(int p=j;p<n1;p++)
    {
        a[k++]=a2[p];
    }
}

void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        
        merge(a,l,mid,r);
    }
}

int main()
{
    int a[]={38,27,43,3,9,82,10};
    int n=7;
    mergesort(a,0,n-1);
    
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
