#include "board.h"

void layout(char (*A)[10])
{
    int i, j;
    for (i = 0; i <= 9; i++) {
        for (j = 0; j <= 9; j++)
            A[i][j] = ' ';
    }

    A[0][1] = 'a';
    A[0][2] = 'b';
    A[0][3] = 'c';
    A[0][4] = 'd';
    A[0][5] = 'e';
    A[0][6] = 'f';
    A[0][7] = 'g';
    A[0][8] = 'h';

    A[9][1] = 'a';
    A[9][2] = 'b';
    A[9][3] = 'c';
    A[9][4] = 'd';
    A[9][5] = 'e';
    A[9][6] = 'f';
    A[9][7] = 'g';
    A[9][8] = 'h';

    A[1][0] = '8';
    A[2][0] = '7';
    A[3][0] = '6';
    A[4][0] = '5';
    A[5][0] = '4';
    A[6][0] = '3';
    A[7][0] = '2';
    A[8][0] = '1';

    A[1][9] = '8';
    A[2][9] = '7';
    A[3][9] = '6';
    A[4][9] = '5';
    A[5][9] = '4';
    A[6][9] = '3';
    A[7][9] = '2';
    A[8][9] = '1';

    A[1][1] = 'R';
    A[1][2] = 'N';
    A[1][3] = 'B';
    A[1][4] = 'Q';
    A[1][5] = 'K';
    A[1][6] = 'B';
    A[1][7] = 'N';
    A[1][8] = 'R';

    A[8][1] = 'r';
    A[8][2] = 'n';
    A[8][3] = 'b';
    A[8][4] = 'q';
    A[8][5] = 'k';
    A[8][6] = 'b';
    A[8][7] = 'n';
    A[8][8] = 'r';

    A[2][1] = 'P';
    A[2][2] = 'P';
    A[2][3] = 'P';
    A[2][4] = 'P';
    A[2][5] = 'P';
    A[2][6] = 'P';
    A[2][7] = 'P';
    A[2][8] = 'P';

    A[7][1] = 'p';
    A[7][2] = 'p';
    A[7][3] = 'p';
    A[7][4] = 'p';
    A[7][5] = 'p';
    A[7][6] = 'p';
    A[7][7] = 'p';
    A[7][8] = 'p';
}

void fboard(char (*A)[10])
{
    FILE* ff;
    ff = fopen("Board.txt", "a");
    int i, j;
    for (i = 0; i <= 9; i++) {
        fprintf(ff, "\n");
        for (j = 0; j <= 9; j++)
            fprintf(ff, " %c ", A[i][j]);
    }
    fclose(ff);
}

void board(int xx, int yy, int xx1, int yy1)
{
    FILE* ff;
    ff = fopen("Board.txt", "a");
    fprintf(ff, "\n");
    fprintf(ff, " %c%d %c%d ", xx, yy, xx1, yy1);
    fprintf(ff, "\n");
    fclose(ff);
}

bool move(int y, int x, int y1, int x1, char (*A)[10])
{
    if (A[y][x] == 'p') // white pawns
    {
        if (A[y1][x1] == ' ' && x == x1 && abs(y1 - y) <= 2) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        if (A[y1][x1] != ' ' && A[y1][x1] >= 65 && A[y1][x1] <= 90
            && ((y - 1 == y1 && x - 1 == x1) || (y - 1 == y1 && x + 1 == x1))) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        return false;
    }
    if (A[y][x] == 'P') // black pawns
    {
        if (A[y1][x1] == ' ' && x == x1 && abs(y1 - y) <= 2) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        if (A[y1][x1] != ' ' && A[y1][x1] >= 97 && A[y1][x1] <= 122
            && ((y + 1 == y1 && x - 1 == x1) || (y + 1 == y1 && x + 1 == x1))) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        return false;
    }
    if (A[y][x] == 'r') // white rooks
    {
        if (A[y1][x1] == ' ' && (x == x1 || y == y1)) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        if (A[y1][x1] != ' ' && A[y1][x1] >= 65 && A[y1][x1] <= 90
            && (x == x1 || y == y1)) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        return false;
    }
    if (A[y][x] == 'R') // black rooks
    {
        if (A[y1][x1] == ' ' && (x == x1 || y == y1)) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        if (A[y1][x1] != ' ' && A[y1][x1] >= 97 && A[y1][x1] <= 122
            && (x == x1 || y == y1)) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        return false;
    }
    if (A[y][x] == 'n') // while knight (horse)
    {
        if (A[y1][x1] == ' ' && (pow(x1 - x, 2) + pow(y1 - y, 2)) == 5) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        if (A[y1][x1] != ' ' && A[y1][x1] >= 65 && A[y1][x1] <= 90
            && (pow(x1 - x, 2) + pow(y1 - y, 2)) == 5) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        return false;
    }
    if (A[y][x] == 'N') // black knight (horse)
    {
        if (A[y1][x1] == ' ' && (pow(x1 - x, 2) + pow(y1 - y, 2)) == 5) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        if (A[y1][x1] != ' ' && A[y1][x1] >= 97 && A[y1][x1] <= 122
            && (pow(x1 - x, 2) + pow(y1 - y, 2)) == 5) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        return false;
    }
    if (A[y][x] == 'b') // bishop white (elephant)
    {
        if (A[y1][x1] == ' ' && abs(y1 - y) == abs(x1 - x)) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        if (A[y1][x1] != ' ' && A[y1][x1] >= 65 && A[y1][x1] <= 90
            && abs(y1 - y) == abs(x1 - x)) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        return false;
    }
    if (A[y][x] == 'B') // bishop black (elephant)
    {
        if (A[y1][x1] == ' ' && abs(y1 - y) == abs(x1 - x)) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        if (A[y1][x1] != ' ' && A[y1][x1] >= 97 && A[y1][x1] <= 122
            && abs(y1 - y) == abs(x1 - x)) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        return false;
    }
    if (A[y][x] == 'q') // white queen (ferz')
    {
        if (A[y1][x1] == ' '
            && (x == x1 || y == y1 || (abs(y1 - y) == abs(x1 - x)))) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        if (A[y1][x1] != ' '
            && (x == x1 || y == y1 || (abs(y1 - y) == abs(x1 - x)))
            && A[y1][x1] >= 65 && A[y1][x1] <= 90) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        return false;
    }
    if (A[y][x] == 'Q') // black queen (ferz')
    {
        if (A[y1][x1] == ' '
            && (x == x1 || y == y1 || (abs(y1 - y) == abs(x1 - x)))) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        if (A[y1][x1] != ' '
            && (x == x1 || y == y1 || (abs(y1 - y) == abs(x1 - x)))
            && A[y1][x1] >= 97 && A[y1][x1] <= 122) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        return false;
    }
    if (A[y][x] == 'k') // white king
    {
        if (A[y1][x1] == ' ' && (abs(y1 - y) == 1 || abs(x1 - x) == 1)) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        if (A[y1][x1] != ' ' && (abs(y1 - y) == 1 || abs(x1 - x) == 1)
            && A[y1][x1] >= 65 && A[y1][x1] <= 90) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        return false;
    }
    if (A[y][x] == 'K') // black king
    {
        if (A[y1][x1] == ' ' && (abs(y1 - y) == 1 || abs(x1 - x) == 1)) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        if (A[y1][x1] != ' ' && (abs(y1 - y) == 1 || abs(x1 - x) == 1)
            && A[y1][x1] >= 97 && A[y1][x1] <= 122) {
            A[y1][x1] = A[y][x];
            A[y][x] = ' ';
            fboard(A);
            return true;
        }
        return false;
    }
    return false;
}
