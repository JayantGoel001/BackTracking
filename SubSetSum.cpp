#include<iostream>
using namespace std;
void printSolution(int *ar,int n)
{
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        if(ar[i]!=0)
        {
            cout<<ar[i]<<" ";
        }
    }
}
void solveSumUtil(int *ar,int n,int x,int gs,int calSum,int *ele,int e_size)
{
    if(gs==calSum)
    {
        printSolution(ele,e_size);
        //solveSumUtil(ar,n,x+1,gs,calSum-ar[x],ele,e_size-1);
    }
    else
    {
        for(int i=x;i<n;i++)
        {
            ele[e_size]=ar[i];
            solveSumUtil(ar,n,i+1,gs,calSum+ar[i],ele,e_size+1);
        }
    }
}
void solveSum(int *ar,int n,int gs)
{
    int *ele=new int[n];
    solveSumUtil(ar,n,0,gs,0,ele,0);
}
int main()
{
    cout<<"Enter the value of n:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the value of array:\n";
    int *ar=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int sum;
    cout<<"Enter the sum :\n";
    cin>>sum;
    solveSum(ar,n,sum);
}
