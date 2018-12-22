#include <iostream>
using namespace std;

int subarray(int a[],int n,int k)
{
    int i,sum=0,start=0;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>k)
        {
            while(sum>k && start<i)
            {
                sum-=a[start];
                start++;
            }
        }
        if(sum==k)
        {
            cout<<"indexes : "<<start<<","<<i<<"\n";
        }
    }
}

int main()
{
    int a[]={1,4,20,2,10,5};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 5;
    subarray(a,n,k);
    return 0;
}
