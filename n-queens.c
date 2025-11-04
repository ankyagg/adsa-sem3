#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5

int solution_counter = 0;

void print_board(char board[N][N]){
    printf("Solution #%d \n",++solution_counter);
    for(int i=0;i<N;i++){
        printf("|");
        for(int j=0;j<N;j++){
            printf(" %c |",board[i][j]);
        }
    printf("\n");
    }
    printf("----------------\n");
}

bool isSafe(char board[N][N],int row,int col){
    int i , j;

    //for uppper column (vertically)
    for(i=0;i<row;i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    //for upper left diagonal
    for(i=row,j=col;i>=0 && j>=0 ; i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    //for upper right diagonal
    for(i=row,j=col;i>=0 && j<N ; i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
}

void nqueens_solver(char board[N][N],int row){
    if(row==N){
        print_board(board);
        return;
    }

    for(int col=0;col<N;col++){
        if(isSafe(board,row,col)){
            //to place the queen at row x column
            board[row][col]='Q';
            // to place another queen in the next row ...
            nqueens_solver(board,row+1);
            //if the very next column cant place the queen .. so we backtrack and remove the queen placed currently at row x column and try some other way.
            board[row][col] = '.';
        }
    }
}

int main(){
    char board[N][N];
    for(int i = 0; i<N;i++){
        for(int j = 0 ; j<N;j++){
            board[i][j] = '.';
        }
    }
    nqueens_solver(board,0);

    if(solution_counter == 0){
        printf("No solution found");
    }
    else{
        printf("%d no. of solutions found",solution_counter);
    }
    return;
}
