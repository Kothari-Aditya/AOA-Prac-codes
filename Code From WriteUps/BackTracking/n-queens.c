#include<stdio.h>
#include<stdbool.h>

#define N 8 // Change N to the desired board size

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    //Check for queens in this row on the left side
    for(i=0; i<N; i++)
    {
        if(board[row][i])
            return false;
    }

    //Check for queens in this column
    for(i=0; i<N; i++)
    {
        if(board[i][col])
            return false;
    }

    //Check upper diagonal on the left side
    for(i=row, j=col; i>=0 && j>=0; i--, j--)
    {
        if(board[i][j])
            return false;
    }

    //Check lower diagonal on the left side
    for(i=row, j=col; i<N && j>=0; i++, j--)
    {
        if(board[i][j])
            return false;
    }

    //Check upper diagonal on the right side
    for(i=row, j=col; i>=0 && j<N; i--, j++)
    {
        if(board[i][j])
            return false;
    }

    return true;
}

bool solveNQueens(int board[N][N], int col)
{
    int i;
    if(col>=N)
        return true;

    for(i=0; i<N; i++)
    {
        if(isSafe(board, i, col))
        {
            board[i][col] = 1;

            if(solveNQueens(board, col+1))
                return true;

            //If placing the queen in board[i][col] doesnt lead to a solution, backtrack
            board[i][col] = 0;
        }
    }
    return false;
}

int printBoard(int board[N][N])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int board[N][N] = {0}; // Initialize chess board with all 0's

    if(solveNQueens(board, 0))
    {
        printf("Solution Exists: \n");
        printBoard(board);
    }
    else
    {
        printf("No solution exists for N = %d\n",N);
    }
    return 0;
}
