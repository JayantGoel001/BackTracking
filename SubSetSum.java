import java.io.*;
import java.lang.*;
import java.util.*;
class SubSetSum
{
    public static void printSolution(int ar[],int n)
    {
        for(int i=0;i<n;i++)
        {
            System.out.print(ar[i]+" ");
        }
        System.out.println();
    }
    public static void SSSUtil(int ar[],int n,int gs,int temp[],int x,int sum,int temp_size)
    {
        if(gs==sum)
        {
            printSolution(temp,temp_size);
        }
        else
        {
            for(int i=x;i<n;i++)
            {
                temp[temp_size]=ar[i];
                SSSUtil(ar,n,gs,temp,i+1,sum+ar[i],temp_size+1);
            }
        }
    }
    public static void SSS(int ar[],int n,int gs)
    {
        int temp[]=new int[n];
        int temp_size=0;
        SSSUtil(ar,n,gs,temp,0,0,temp_size);
    }
    public static void main(String args[])throws IOException
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of elements:");
        int n=sc.nextInt();
        int ar[]=new int[n];
        System.out.println("Enter the elements of array:");
        for(int i=0;i<n;i++)
        {
            ar[i]=sc.nextInt();
        }
        System.out.println("Enter the Sum :");
        int gs=sc.nextInt();
        SSS(ar,n,gs);
    }
}