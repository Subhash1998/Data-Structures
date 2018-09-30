#include <iostream>
using namespace std;


bool unassigned(int grid[9][9],int &i,int &j)
{
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(grid[i][j]==0)
                return true;
        }
    }
    return false;
}

bool incol(int grid[9][9],int j,int num)
{
    for(int p=0;p<9;p++)
    {
        if(grid[p][j]==num)
            return true;
    }
    return false;
}

bool inrow(int grid[9][9],int i,int num)
{
    for(int p=0;p<9;p++)
    {
        if(grid[i][p]==num)
            return true;
    }
    return false;
}

bool inbox(int grid[9][9],int i,int j,int num)
{
    for(int p=i;p<3;p++)
    {
        for(int q=j;q<3;q++)
        {
            if(grid[p][q]==num)
                return true;
        }
    }
    return false;
}

bool check_nine(int grid[9][9],int i,int j,int num)
{
    return ((!incol(grid,j,num)) && (!inrow(grid,i,num)) && !(inbox(grid,i-i%3,j-j%3,num)));
}


bool solve(int grid[9][9])
{
    int i,j;

    if(unassigned(grid,i,j)==false)
        return true;

    for(int num=1;num<=9;num++)
    {
        if(check_nine(grid,i,j,num))
        {
            grid[i][j]=num;

            if(solve(grid)==true)
                return true;

            grid[i][j]=0;
        }
    }

    return false;
}

int main()
{
    int n;
    // cin>>n;
    n=9;
    int grid[9][9]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if(solve(grid))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<grid[i][j]<<" ";

            cout<<"\n";
        }
    }
    else
        cout<<"Solution does not exists..!";
    return 0;
}
