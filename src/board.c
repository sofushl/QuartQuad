#include "runinfo.c"
#include <stdio.h>

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
};

void printline() {
  printf("\n");
  printf("—");
  for (int j = 0; j < WIDHT * 2; j++) {
    printf("—");
  };
  printf("\n");
};

void showBoard(char board[HEIGHT][WIDHT]) {
  printline();
  for (int i = 0; i < HEIGHT; i++) {
    printf("│");
    for (int j = 0; j < WIDHT; j++) {
      printf("%c", board[i][j]);
      printf("│");
    };
    printline();
  };
}

void runBoard(char board[HEIGHT][WIDHT], struct runInfo ri) {

  setBoard(board, ri);
  showBoard(board);
}
