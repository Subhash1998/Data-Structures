#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[]={1, 4, -7, 0, 5};
    int sum=6,f=0;
    set<int> s;
    int n = 5;
    for(int i=0;i<n;i++)
    {
        if(s.find(a[i])!=s.end())
        {
            f=1;
            cout<<a[i]<<" "<<sum-a[i]<<"\n";
            break;
        }
        s.insert(sum-a[i]);
    }
    
    if(f)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
