#include<iostream>
#define int long long int
using namespace std;
void printSolution(int *ar,int n){
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}
void AllBinaryCodeUtil(int *ar,int n,int i){
    if(i==n){
        printSolution(ar,n);
    }else{
        ar[i]=0;
        AllBinaryCodeUtil(ar,n,i+1);
        ar[i]=1;
        AllBinaryCodeUtil(ar,n,i+1);
    }
}
void AllBinaryCode(int n){
    int *ar=new int[n];
    for(int i=0;i<n;i++){
        ar[i]=0;
    }
    AllBinaryCodeUtil(ar,n,0);
}
int32_t main(){
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    AllBinaryCode(n);
}
