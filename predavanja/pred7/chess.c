#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[8][9];

char jmp(int col, int row, int dir)
{
    int const dcol[] = {2,1,-2,-2,-2,-1,1,2};
    int const drow[] = {1,2,2,1,-1,-2,-2,-1};

    if (col + dcol[dir] < 0 || (col + dcol[dir]) > 7) return '\0';
    if (row +drow[dir] < 0 || (row +drow[dir]) > 7) return '\0';

    return board[col + dcol[dir]][row + drow[dir]];

}

int solve(int col, int row)
{
    if (row >= 8) return 0;
    if (col >= 8) return solve(0,row +1);
    if (board[row][col] != '.') return solve(col + 1, row);

    int first = solve(++col, row);
    board[row][col] = 'N';
}

int main()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            board[i][j] = '.';
        board[i][8] = '\n';
    }
        board[7][8] = '\0';

    // to dela zto, ker printf za string printa do \0. Ker smo dali \n chars na koncu stringa
    // bo printf izpisal ceu array -> ULTRA GAY
    printf("%s\n", (char*)board);

    return 0;
}