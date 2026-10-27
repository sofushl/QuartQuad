#include "board.c"
#include "control.c"

#define HEIGHT 20
#define WIDHT 10

int main() {
  char board[HEIGHT][WIDHT];
  int pos[2] = {0, 0};
  char c = 't';

  while (c != 'q') {
    setBoard(board, pos);
    showBoard(board);
    c = press(pos);
  }

  printf("Exiting...\n");
  return 0;
}
