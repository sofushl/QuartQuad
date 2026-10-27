#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "board.c"
#include "control.c"
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

  setup();

  char board[HEIGHT][WIDHT];

  pid_t child_pid = fork();
  if (child_pid == 0) { // child
    while (*(ri.c) != 'q') {
      press(ri);
    }
  } else {
    while (*(ri.c) != 'q') {
      runBoard(board, ri);

      usleep(50000);
    }
  }
  return 0;
}
