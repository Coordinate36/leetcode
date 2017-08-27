#include <stdio.h>

/*void dfs(char **board, int m, int n, int boardRowSize, int boardColSize) {
    if (m < 0 || m >= boardRowSize || n < 0 || n < boardColSize) {
        return;
    }
    board[m][n] = 1;
    dfs(board, m - 1, n, boardRowSize, boardColSize);
    dfs(board, m + 1, n, boardRowSize, boardColSize);
    dfs(board, m, n - 1, boardRowSize, boardColSize);
    dfs(board, m, n + 1, boardRowSize, boardColSize);
}*/

void dfs(char **board, int m, int n, int boardRowSize, int boardColSize) {
    if (m > 0 && board[m - 1][n] == 'O') {
        board[m - 1][n] =  1;
        dfs(board, m - 1, n, boardRowSize, boardColSize);
    }
    if (m < boardRowSize - 1 && board[m + 1][n] == 'O') {
        board[m + 1][n] =  1;
        dfs(board, m + 1, n, boardRowSize, boardColSize);
    }
    if (n > 0 && board[m][n - 1] == 'O') {
        board[m][n - 1] =  1;
        dfs(board, m, n - 1, boardRowSize, boardColSize);
    }
    if (m < boardColSize - 1 && board[m][n + 1] == 'O') {
        board[m][n + 1] =  1;
        dfs(board, m, n + 1, boardRowSize, boardColSize);
    }
}

void solve(char** board, int boardRowSize, int boardColSize) {
    int i, j;
    for (i = 0; i < boardRowSize; i++) {
        if (board[i][0] == 'O') {
            board[i][0] = 1;
            dfs(board, i, 1, boardRowSize, boardColSize);
        }
        if (board[i][boardColSize - 1] == 'O') {
            board[i][boardColSize - 1] = 1;
            dfs(board, i, boardColSize - 2, boardRowSize, boardColSize);
        }
    }
    for (j = 0; j < boardColSize; j++) {
        if (board[0][j] == 'O') {
            board[0][j] = 1;
            dfs(board, 1, j, boardRowSize, boardColSize);
        }
        if (board[boardRowSize - 1][j] == 'O') {
            board[boardRowSize - 1][j] = 1;
            dfs(board, boardRowSize - 2, j, boardRowSize, boardColSize);
        }
    }

    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if (board[i][j] != 1) {
                board[i][j] = 'X';
            } else {
                board[i][j] = 'O';
            }
        }
    }
}

int main()
{
    char board[3][3];
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = 'O';
        }
    }
    solve(board, 3, 3);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
    }
}