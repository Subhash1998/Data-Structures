#include <iostream>

using namespace std;

void dfs(char a[100][100],int i,int j,bool visited[100][100],int n,int m)
{
    visited[i][j]=true;
    if(i+1<n && a[i+1][j]=='x' && visited[i+1][j]==0)
        dfs(a,i+1,j,visited,n,m);
    if(i-1>=0 && a[i-1][j]=='x' && visited[i-1][j]==0)
        dfs(a,i-1,j,visited,n,m);
    if(j+1<m && a[i][j+1]=='x' && visited[i][j+1]==0)
        dfs(a,i,j+1,visited,n,m);
    if(j-1>=0 && a[i][j-1]=='x' && visited[i][j-1]==0)
        dfs(a,i,j-1,visited,n,m);
}

int main()
{
    char a[100][100];
    int i,j,n,m,count=0;
    bool visited[100][100];
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(j=0;j<m;j++)
        {
            a[i][j]=s[j];
            visited[i][j]=false;
        }
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]=='x' && visited[i][j]==false)
            {
                dfs(a,i,j,visited,n,m);
                count++;
            }
        }
    }
    
    cout<<count;
    
    return 0;
}
