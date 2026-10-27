#include "runinfo.c"
#include "termios_getch.c"

struct runInfo press(struct runInfo ri) {

  char k = getch();

  switch (k) {
  case 65: // key up
    (*ri.y)--;
    break;
  case 66: // key down
    (*ri.y)++;
    break;
  case 67: // key right
    (*ri.x)++;
    break;
  case 68: // key left
    (*ri.x)--;
    break;
  default:
    break;
  }
  *ri.c = k;

  return ri;
}
