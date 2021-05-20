#include<iostream>
#define int long long int
using namespace std;
bool isSafe(int x,int y,int **maze,int N){
    return (x>=0 && x<N && y>=0 && y<N && maze[x][y]==1);
}
void printSolution(int **sol,int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool solveMazeUtil(int **maze,int i,int j,int **sol,int N){
    if(i==N-1 && j==N-1){
        sol[i][j]=1;
        return true;
    }
    if (!isSafe(i, j, maze, N))
        return false;
    sol[i][j]=1;
    if (!solveMazeUtil(maze, i + 1, j, sol, N)) {
        if (!solveMazeUtil(maze, i, j + 1, sol, N)) {
            sol[i][j] = 0;
            return false;
        } else {
            return true;
        }
    } else {
        return true;
    }
}
bool solveMaze(int **maze,int N){
    int **sol=new int*[N];
    for(int i=0;i<N;i++){
        sol[i]=new int[N];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            sol[i][j]=0;
        }
    }
    if (solveMazeUtil(maze, 0, 0, sol, N)) {
        printSolution(sol, N);
        return true;
    } else {
        cout << "Solution Does not exists";
        return false;
    }
}
int32_t main(){
    int **maze=new int*[4];
    for(int i=0;i<4;i++){
        maze[i]=new int[4];
    }
    maze[0][0]=1;
    maze[0][1]=0;
    maze[0][2]=0;
    maze[0][3]=0;

    maze[1][0]=1;
    maze[1][1]=1;
    maze[1][2]=0;
    maze[1][3]=1;

    maze[2][0]=0;
    maze[2][1]=1;
    maze[2][2]=0;
    maze[2][3]=0;

    maze[3][0]=1;
    maze[3][1]=1;
    maze[3][2]=1;
    maze[3][3]=1;
    solveMaze(maze,4);
}
