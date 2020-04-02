#include<iostream>
#include<math.h>
using namespace std;
void printSolution(int *ar,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}
void getPrimesSumUtil(int *ar,int n,int p,int s,int csum,int x,bool *isPrime)
{
    if(s==csum && n==x)
    {
        printSolution(ar,n);
    }
    else
    {
        for(int i=p+1;i<=s;i++)
        {
            if(isPrime[i]==true && x<=n)
            {
                ar[x]=i;
                getPrimesSumUtil(ar,n,i+1,s,csum+i,x+1,isPrime);
                ar[x]=-1;
            }
        }
    }
}
void getPrimesSum(int p,int n,int s)
{
    int *ar=new int[n];
    for(int i=0;i<n;i++)
    {
        ar[i]=-1;
    }
    bool *isPrime=new bool[s+1];
    for(int i=0;i<=s;i++)
    {
        isPrime[i]=true;
    }
    for(int i=2;i<=s;i++)
    {
        for(int j=i*i;j<=s;j+=i)
        {
            isPrime[j]=false;
        }
    }
    isPrime[1]=false;
    cout<<"\nSolution\n";
    getPrimesSumUtil(ar,n,p,s,0,0,isPrime);

}
int main()
{
    int n,s,p;
    cout<<"Enter the value of n,p,s:\n";
    cin>>n;
    cin>>p;
    cin>>s;
    getPrimesSum(p,n,s);
}
