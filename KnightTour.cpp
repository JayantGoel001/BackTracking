#include<iostream>
using namespace std;
void printSolution(int **sol)
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout<<sol[i][j]<<"  ";
        }
        cout<<endl;
    }
}
int isSafe(int x,int y,int **sol)
{
    return (x>=0 && x<8 && y>=0 && y<8 && sol[x][y]==-1);
}
int solveKTUtil(int x,int y,int movei,int **sol,int xMoves[],int yMoves[])
{
    int next_x,next_y;
    if(movei==64)
    {
        return 1;
    }
    for(int k=0;k<8;k++)
    {
        next_x=x+xMoves[k];
        next_y=y+yMoves[k];
        if(isSafe(next_x,next_y,sol))
        {
            sol[next_x][next_y]=movei;
            if(solveKTUtil(next_x,next_y,movei+1,sol,xMoves,yMoves)==1)
            {
                return 1;
            }
            else
            {
                sol[next_x][next_y]=-1;
            }
        }
    }
    return 0;
}
int solveKT()
{
    int **sol=new int*[8];
    for(int i=0;i<8;i++)
    {
        sol[i]=new int[8];
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            sol[i][j]=-1;
        }
    }
    int xMoves[8]={2,1,-1,-2,-2,-1,1,2};
    int yMoves[8]={1,2,2,1,-1,-2,-2,-1};
    sol[0][0]=0;
    if(solveKTUtil(0,0,1,sol,xMoves,yMoves)==0)
    {
        cout<<"Solution does not exist";
        return 0;
    }
    else
    {
        printSolution(sol);
    }
    return 1;
}
int main()
{
    solveKT();
}
