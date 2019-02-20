video :- https://www.youtube.com/watch?v=GTJr8OvyEVQ&t=688s

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define N 1000000

int main()
{
    string txt,pat;
    cin>>txt>>pat;
    ll lps[N];
    lps[0]=0;
    ll i=1,j=0;
    while(i<pat.length())
    {
        if(pat[i]==pat[j])
        {
            lps[i]=j+1;
            j++;
            i++;
        }
        else
        {
            if(j==0)
            {
                lps[i]=0;
                i++;
            }
            else
                j=lps[j-1];
        }
    }
    i=0;
    j=0;
    while(i<txt.length())
    {
        if(txt[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==pat.length())
        {
            cout<<"found at index = "<<i-j<<"\n";
            j=lps[j-1];
        }
        else if(i<txt.length() && txt[i]!=pat[j])
        {
            if(j==0)
                i++;
            else
                j = lps[j-1];
        }
    }
    return 0;
}
