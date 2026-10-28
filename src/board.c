#include "runinfo.c"
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 20
#define WIDHT 10

void setBoard(char board[HEIGHT][WIDHT], struct runInfo ri) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDHT; j++) {
      // printf("%d, %d, %d, %d\n", i, pos[0], j, pos[1]);
      if (*(ri.y) == i && *(ri.x) == j) {
        board[i][j] = 'O';
      } else {
        board[i][j] = ' ';
      };
    };
  };
}

void addChar(char added, char **p) {
  **p = added;
  (*p)++;
}

void printline(char **p) {
  addChar('\n', p);
  addChar('-', p);
  for (int j = 0; j < WIDHT * 2; j++) {
    addChar('-', p);
  };
  addChar('\n', p);
}

void showBoard(char board[HEIGHT][WIDHT]) {

  char *s = malloc(sizeof(char) * (WIDHT * 2 + 2) * (HEIGHT * 2 + 1) + 1);
  char *p = s;
  printline(&p);
  for (int i = 0; i < HEIGHT; i++) {
    addChar('|', &p);
    for (int j = 0; j < WIDHT; j++) {
      addChar(board[i][j], &p);
      addChar('|', &p);
    };
    printline(&p);
  };
  fflush(stdout);
  printf("%s", s);
  fflush(stdout);
}

void runBoard(char board[HEIGHT][WIDHT], struct runInfo ri) {
  setBoard(board, ri);
  showBoard(board);
}
