#include<iostream>
using namespace std;
void printSolution(int *path,int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<path[i]<<" ";
    }
}
void possiblePathUtil(int *ar,int m,int n,int *path,int x,int y,int z){
    if(x==m-1){
        for(int k=y;k<n;k++){
            path[z+k-y]=ar[x*n+k];
        }
        printSolution(path,z+n-y);
        return;
    }
    if(y==n-1){
        for(int k=x;k<m;k++){
            path[z+k-x]=ar[k*n+y];
        }
        printSolution(path,z+m-x);
        return;
    }
    path[z]=ar[x*n+y];
    possiblePathUtil(ar,m,n,path,x+1,y,z+1);
    possiblePathUtil(ar,m,n,path,x,y+1,z+1);
}
void possiblePath(int *ar,int m,int n){
    int lengthOfPath=n+m;
    int *path=new int[lengthOfPath];
    for(int i=0;i<lengthOfPath;i++){
        path[i]=0;
    }
    cout<<"Solution:\n";
    possiblePathUtil(ar,m,n,path,0,0,0);
}
int main(){
    int n,m;
    cout<<"Enter the value of n and m:\n";
    cin>>m>>n;
    int *ar=new int[n*m];
    cout<<"Enter the value of array:\n";
    for(int i=0;i<n*m;i++){
        cin>>ar[i];
    }
    possiblePath(ar,m,n);
}
