import java.io.*;
import java.lang.*;
import java.util.*;
class RatInAMaze
{
    public static boolean isSafe(int ar[][],int n,int x,int y)
    {
        return (x>=0 && y>=0 && x<n && y<n && ar[x][y]==1);
    }
    public static void printSolution(int ar[][],int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.print(ar[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void solveRIAM(int ar[][],int n)
    {
        int sol[][]=new int[n][n];
        if(solveRIAMUtil(ar,n,0,0,sol)==0)
        {
            System.out.println("Solution does not exists");
        }
        else
        {
            printSolution(sol,n);
        }
    }
    public static int solveRIAMUtil(int maze[][],int n,int i,int j,int sol[][])
    {
        if(i==n-1 && j==n-1)
        {
            sol[i][j]=1;
            return 1;
        }
        if(isSafe(maze,n,i,j)==true)
        {
            sol[i][j]=1;
            if(solveRIAMUtil(maze,n,i+1,j,sol)==1)
            {
                return 1;
            }
            else if(solveRIAMUtil(maze,n,i,j+1,sol)==1)
            {
                return 1;
            }
            else
            {
                sol[i][j]=0;
            }
        }
        return 0;
    }
    public static void main(String args[])throws IOException
    {
        int n=4;
        int ar[][]=new int[n][n];
        ar[0][0]=1;
        ar[1][0]=1;
        ar[1][1]=1;
        ar[2][1]=1;
        ar[1][3]=1;
        ar[3][0]=1;
        ar[3][1]=1;
        ar[3][2]=1;
        ar[3][3]=1;
        solveRIAM(ar,n);
    }
}