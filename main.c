#include "termios_getch.c"
#include <stdio.h>

#define SIZE 4

void setBoard(char board[SIZE][SIZE], int pos[2]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d, %d, %d, %d\n", i, pos[0], j, pos[1]);
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
  for (int j = 0; j < SIZE * 2 + 1; j++) {
    printf("-");
  };
  printf("\n");
};

void showBoard(char board[SIZE][SIZE]) {
  printline();
  for (int i = 0; i < SIZE; i++) {
    printf("|");
    for (int j = 0; j < SIZE; j++) {
      printf("%c|", board[i][j]);
    };
    printline();
  };
}

void sleep_ms(int milliseconds) {
  // Convert milliseconds to microseconds
  usleep(milliseconds * 1000);
}

int main() {
  char c;
  char board[SIZE][SIZE];
  int pos[2] = {0, 0};

  while (c != 'q') {
    setBoard(board, pos);
    showBoard(board);
    c = getch();
    sleep_ms(10);
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
