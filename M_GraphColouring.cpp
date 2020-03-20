#include<iostream>
using namespace std;
void printSolution(int *color,int n)
{
    cout<<"Graph can be colored in this way:\n";
    for(int i=0;i<n;i++)
    {
        cout<<color[i]<<" ";
    }
}
bool isSafe(int **graph,int n,int v,int *color,int c)
{
    for(int i=0;i<n;i++)
    {
        if(graph[v][i]==1 && color[i]==c)
        {
            return false;
        }
    }
    return true;
}
bool graphColorUtil(int **graph,int n,int v,int *color,int m)
{
    if(v==n)
    {
        return true;
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            if(isSafe(graph,n,v,color,i)==true)
            {
                color[v]=i;
                if(graphColorUtil(graph,n,v+1,color,m)==true)
                {
                    return true;
                }
                else
                {
                    color[v]=0;
                }
            }
        }
    }
    return false;
}
void graphColor(int **graph,int n,int m)
{
    int *color=new int[n];
    for(int i=0;i<n;i++)
    {
        color[i]=0;
    }
    if(graphColorUtil(graph,n,0,color,m)==true)
    {
        printSolution(color,n);
    }
    else
    {
        cout<<"Solution Does not exists.";
    }
}
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    int **graph=new int*[n];
    for(int i=0;i<n;i++)
    {
        graph[i]=new int[n];
    }
    cout<<"\nEnter the element of graph in terms of 0 and 1:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    int m;
    cout<<"\n\nEnter the value of m:\n";
    cin>>m;
    graphColor(graph,n,m);
}
