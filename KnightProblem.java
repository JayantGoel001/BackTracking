import java.io.*;
import java.lang.*;
import java.util.*;
class KnightProblem
{
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
    public static boolean  isSafe(int ar[][],int i,int j,int n)
    {
        return (i>=0 && i<n && j>=0 && j<n && (ar[i][j]==-1));
    }
    public static void solveKP(int ar[][],int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ar[i][j]=-1;
            }
        }
        int movex[]={2,1,-1,-2,-2,-1,1,2};
        int movey[]={1,2,2,1,-1,-2,-2,-1};
        ar[0][0]=0;
        int move=1;
        if(solveKTUtil(ar,n,0,0,move,movex,movey)==0)
        {
            System.out.println("Solution does not exists.");
        }
        else
        {
            printSolution(ar,n);
        }
    }
    public static int solveKTUtil(int ar[][],int n,int x,int y,int move,int movex[],int movey[])
    {
        if(move==n*n)
        {
            return 1;
        }
        for(int i=0;i<8;i++)
        {
            int next_x=x+movex[i];
            int next_y=y+movey[i];
            if(isSafe(ar,next_x,next_y,n)==true)
            {
                ar[next_x][next_y]=move;
                if(solveKTUtil(ar,n,next_x,next_y,move+1,movex,movey)==1)
                {
                    return 1;
                }
                else
                {
                    ar[next_x][next_y]=-1;
                }
            }
        }
        return 0;
    }
    public static void main(String args[])throws IOException
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the value of n:");
        int n=sc.nextInt();
        int ar[][]=new int[n][n];
        solveKP(ar,n);
    }
}