#include "termios_getch.c"

char press(int pos[2]) {
  char c = getch();

  switch (c) {
  case 65: // key up
    pos[0]--;
    break;
  case 66: // key down
    pos[0]++;
    break;
  case 67: // key right
    pos[1]++;
    break;
  case 68: // key left
    pos[1]--;
    break;
  default:
    break;
  }
  return c;
}
