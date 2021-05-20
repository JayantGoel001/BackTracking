#include<iostream>
#define int long long int
using namespace std;
void printSolution(int **board){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isSafe(int x,int y,int **board){
    for(int j=0;j<y;j++){
        if(board[x][j]){
            return false;
        }
    }
    int i,j;
    for(i=x,j=y;i>=0&&j>=0;i--,j--){
        if(board[i][j]){
            return false;
        }
    }
    for(i=x,j=y;i<8&&j>=0;i++,j--){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}
bool solveNQUtil(int **board,int col){
    if(col>=8){
        return true;
    }
    for(int i=0;i<8;i++){
        if(isSafe(i,col,board)){
            board[i][col]=1;
            if(solveNQUtil(board,col+1)){
                return true;
            } else {
                board[i][col]=0;
            }
        }
    }
    return false;
}
bool solveNQ()
{
    int **board=new int*[8];
    for(int i=0;i<8;i++){
        board[i]=new int[8];
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]=0;
        }
    }
    if (solveNQUtil(board, 0)) {
        printSolution(board);
        return true;
    } else {
        cout << "Solution does not exists";
        return false;
    }
}
int32_t main(){
    solveNQ();
}
