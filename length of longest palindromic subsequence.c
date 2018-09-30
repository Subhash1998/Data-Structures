#include <bits/stdc++.h>
using namespace std;
int lps(char *seq,int i,int j)
{
    if(i==j)
        return 1;
    if(i+1==j && seq[i]==seq[j])
        return 2;
    if(seq[i]==seq[j])
        return lps(seq,i+1,j-1) + 2;
    else
        return max(lps(seq,i+1,j),lps(seq,i,j-1));
}

int main()
{
    char seq[10000];
    cin>>seq;
    int siz=strlen(seq);
    cout<<lps(seq,0,siz-1);
    return 0;
}
