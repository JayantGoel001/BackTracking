import java.io.*;
import java.lang.*;
import java.util.*;
class NQueenProblem
{
    public static boolean isSafe(int ar[][],int n,int x,int y)
    {
        for(int j=0;j<y;j++)
        {
            if(ar[x][j]==1)
            {
                return false;
            }
        }
        int i,j;
        for(i=x,j=y;i>=0 && j>=0;i--,j--)
        {
            if(ar[i][j]==1)
            {
                return false;
            }
        }
        for(i=x,j=y;i<n&&j>=0 ;i++,j--)
        {
            if(ar[i][j]==1)
            {
                return false;
            }
        }
        return true;
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
    public static int solveNQUtil(int board[][],int n,int x,int y)
    {
        if(y==n)
        {
            return 1;
        } 
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,n,i,y)==true)
            {
                board[i][y]=1;
                if(solveNQUtil(board,n,i,y+1)==1)
                {
                    return 1;
                }
                else
                {
                    board[i][y]=0;
                }
            }
        }
        return 0;
    }
    public static void solveNQueen(int board[][],int n)
    {
       if(solveNQUtil(board,n,0,0)==0)
       {
           System.out.println("Solution does not exist");
       }
       else
       {
           printSolution(board,n);
       }
    }
    public static void main(String args[])throws IOException
    {
        int board[][]=new int[8][8];
        solveNQueen(board,8);
    }
}