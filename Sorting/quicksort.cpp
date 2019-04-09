#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll partition(ll arr[],ll low,ll high)
{
    ll pivot=arr[high];
    ll i=low-1,j=low;
    while(j<high)
    {
        if(arr[j]<=pivot)
        {
            i++;
            ll temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        j++;
    }
    ll temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    
    return (i+1);
}

void quicksort(ll arr[],ll low,ll high)
{
    if(low<high)
    {
        ll pi=partition(arr,low,high);
        
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    quicksort(arr,0,n-1);
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
