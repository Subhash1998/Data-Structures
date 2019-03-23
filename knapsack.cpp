#include <iostream>
using namespace std;

#define N 1000000

//recursion
// int knapsack(int wt[],int val[],int n,int w)
// {
//     if(n==0 || w==0)
//         return 0;
    
//     if(wt[n-1]>w)
//         return knapsack(wt,val,n-1,w);
    
//     return max(val[n-1]+knapsack(wt,val,n-1,w-wt[n-1]) , knapsack(wt,val,n-1,wt[n-1]));
// }

//dynamic programming
int knapsack(int wt[],int val[],int n,int w)
{
    int dp[n+1][w+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(wt[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j] , val[i-1] + dp[i-1][j-wt[i-1]]);
        }
    }
    return dp[n][w];
}



int main()
{
    int wt[N],val[N];
    int i,n,w;
    cin>>n>>w;
    for(i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    cout<<knapsack(wt,val,n,w);
    return 0;
}
