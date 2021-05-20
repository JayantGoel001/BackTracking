#include<iostream>
using namespace std;
void printSolution(int **ar,int n){
    cout<<"\nSolution :\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isSafe(int **ar,int n,int x,int y){
    cout<<x;
    cout<<" ";
    cout<<y<<endl;
    if(x<n && y<n && x>=0 && y>=0 && ar[x][y]!=0){
        return true;
    } else {
        return false;
    }
}
bool ratInAMazeUtil(int **ar,int n,int x,int y,int **path){
    if(x==n-1 && y==n-1){
        return true;
    }else{
        for(int i=1;i<=ar[x][y];i++){
            if (isSafe(ar, n, (x + i), y)) {
                path[x + i][y] = 1;
                if (!ratInAMazeUtil(ar, n, x + i, y, path)) {
                    path[x + i][y] = 0;
                } else {
                    return true;
                }
            }
            if (!isSafe(ar, n, x, y + i))
                continue;
            path[x][y+i]=1;
            if (!ratInAMazeUtil(ar, n, x, y + i, path)) {
                path[x][y + i] = 0;
            } else {
                return true;
            }
        }
    return false;
    }

}
void ratInAMaze(int **ar,int n){
    int **path=new int*[n];
    for(int i=0;i<n;i++){
        path[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            path[i][j]=0;
        }
    }
    path[0][0]=1;
    path[n-1][n-1]=1;
    if (!ratInAMazeUtil(ar, n, 0, 0, path)) {
        cout << "\nSolution does not exists";
    } else {
        printSolution(path, n);
    }
}

int main(){
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    int **ar=new int*[n];
    for(int i=0;i<n;i++){
        ar[i]=new int[n];
    }
    cout<<"\nEnter the value of array:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ar[i][j];
        }
    }
    ratInAMaze(ar,n);
}
