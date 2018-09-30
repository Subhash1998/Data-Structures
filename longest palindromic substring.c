#include <bits/stdc++.h>
using namespace std;

void lps(string str)
{
    int n,i,j,start,max,k;
    n=str.size();
    bool table[n][n];

    memset(table,0,sizeof(table));

    for(i=0;i<n;i++)
        table[i][i]=true;

    for(i=0;i<n-1;i++)
    {
        if(str[i]==str[i+1])
        {
            table[i][i+1]=true;
            start=i;
            max=2;
        }
    }

    for(i=3;i<=n;i++)
    {
        for(j=0;j<n-i+1;j++)
        {
            k=i-1+j;
            if(table[j+1][k-1] && str[k]==str[j])
            {
                table[j][k]=true;
                if(max<i)
                {
                    start=j;
                    max=i;
                }
            }

        }
    }

    cout<<"Longest palidromic substring is :- ";
    for(i=start;i<max+start;i++)
        cout<<str[i];
    cout<<"\nLength of lps is :- "<<max;
}

int main()
{
    string str;
    cin>>str;
    lps(str);
    return 0;
}
