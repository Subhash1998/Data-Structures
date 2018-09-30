#include <iostream>
using namespace std;

#define N 8

void printgrid(int grid[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<grid[i][j]<<" ";
        cout<<"\n";
    }
}

bool check(int grid[N][N],int i,int j)
{
    int x,y;
    for(x=0;x<j;x++)
    {
        if(grid[i][x]==1)
            return false;
    }

    for(x=i-1,y=j-1;x>=0 && y>=0;x--,y--)
    {
        if(grid[x][y]==1)
            return false;
    }

    for(x=i+1,y=j-1;x<N && y>=0;x++,y--)
    {
        if(grid[x][y]==1)
            return false;
    }

    return true;
}

bool solve(int grid[N][N],int col)
{
    int i;

    if(col>=N)
        return true;

    for(i=0;i<N;i++)
    {
        if(check(grid,i,col))
        {
            grid[i][col]=1;

            if(solve(grid,col+1))
                return true;

            grid[i][col]=0;
        }
    }
}

int main()
{
    int grid[N][N]={ {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };


    if(solve(grid,0))
        printgrid(grid);
    else
        cout<<"Solution does not exist\n";
    return 0;
}
