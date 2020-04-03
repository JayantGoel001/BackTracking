#include<iostream>
#include<vector>
using namespace std;
void printSolution(vector<int> ar,int n)
{
    cout<<"N Bit Gray Codes is:\n";
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}
void NBitGrayUtil(vector<int> &genCodes,int n,int &num)
{
    if(n==0)
    {
        genCodes.push_back(num);
    }
    else
    {
        NBitGrayUtil(genCodes,n-1,num);
        num=num^(1<<(n-1));
        NBitGrayUtil(genCodes,n-1,num);
    }
}
void NBitGray(int n)
{
    vector<int> genCodes;
    int num=0;
    NBitGrayUtil(genCodes,n,num);
    printSolution(genCodes,1<<n);
}
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    NBitGray(n);
}
