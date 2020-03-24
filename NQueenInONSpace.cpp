#include<bits/stdc++.h>
using namespace std;
void printSolution(int *ar,int n)
{
    cout<<"\nNQueen can be placed as :\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ar[i]!=j)
            {
                cout<<"0";
            }
            else
            {
                cout<<"1";
            }
        }
        cout<<"\n";
    }
}
bool isSafe(int *ar,int n,int i,int k)
{
    for(int j=0;j<k;j++)
    {
        if(ar[j]==i || abs(ar[j]-i)==abs(j-k))
        {
            return false;
        }
    }
    return true;
}
void nQueens(int *ar,int n,int k)
{
    if(k==n)
    {
        printSolution(ar,n);
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(isSafe(ar,n,i,k)==true)
            {
                ar[k]=i;
                nQueens(ar,n,k+1);
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    int *ar=new int[n];
    for(int i=0;i<n;i++)
    {
        ar[i]=0;
    }
    nQueens(ar,n,0);
}
