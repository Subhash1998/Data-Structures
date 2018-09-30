#include <iostream>
#include<string.h>
using namespace std;

int maxl(int m,int n)
{
    return(m>n ? m :n);
}

void lcs(char X[],char Y[],int m,int n)
{
    int table[m+1][n+1],i,j;

    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
                table[i][j]=0;

            else if(X[i-1]==Y[j-1])
                table[i][j]=1+table[i-1][j-1];

            else
                table[i][j]=maxl(table[i-1][j],table[i][j-1]);
        }
    }

    cout<<"Length of longest common subsequence is :- "<<table[m][n]<<"\n";

    int len=table[m][n];
    char lcs[len+1];

    for(j=n,i=m;j>=1,i>=1;)
    {
        if(maxl(table[i-1][j],table[i][j-1]) != table[i][j])
        {
            lcs[len-1]=X[i-1];
            len--;
            i--;
            j--;
        }
        else if(table[i-1][j]>table[i][j-1])
            i--;
        else
            j--;
    }

    cout<<"Longest common subsequence :- "<<lcs;
}

int main()
{
    char str1[1000],str2[1000];
    cin>>str1>>str2;
    int m= strlen(str1);
    int n= strlen(str2);

    lcs(str1,str2,m,n);
    return 0;
}
