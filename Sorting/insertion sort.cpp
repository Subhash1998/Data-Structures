#include <iostream>
using namespace std;

int main()
{
    int a[]={12,56,43,22,8,6};
    int n=6;
    
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int x = a[i];
        while(j>=0 && a[j]>=x)
        {
            a[j+1]=a[j];
            j--;
        }
        
        a[j+1]=x;
    }
    
    for(int k=0;k<n;k++)
        cout<<a[k]<<" ";
    
    return 0;
}
