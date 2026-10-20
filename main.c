#include "termios_getch.c"
#include <stdio.h>

#define HEIGHT 20
#define WIDHT 10

void setBoard(char board[HEIGHT][WIDHT], int pos[2]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDHT; j++) {
      // printf("%d, %d, %d, %d\n", i, pos[0], j, pos[1]);
      if (pos[0] == i && pos[1] == j) {
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

int main() {
  char c;
  char board[HEIGHT][WIDHT];
  int pos[2] = {0, 0};

  while (c != 'q') {
    setBoard(board, pos);
    showBoard(board);
    c = getch();
    if (c == 'w') {
      pos[0]--;
    } else if (c == 'a') {
      pos[1]--;
    } else if (c == 's') {
      pos[0]++;
    } else if (c == 'd') {
      pos[1]++;
    }
  }

  printf("Exiting...\n");
  return 0;
}
