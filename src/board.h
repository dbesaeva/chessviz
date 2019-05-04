#ifndef BOARD_H_
#define BOARD_H_

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void layout(char (*A)[10]);
void board(int xx, int yy, int xx1, int yy1);
_Bool move(int y, int x, int y1, int x1, char (*A)[10]);

#endif
