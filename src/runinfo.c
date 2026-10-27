#ifndef _RUNINFOSTRUCT_C
#define _RUNINFOSTRUCT_C 1

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static int *x;
static int *y;
static char *c;

struct runInfo {
  int *x;
  int *y;
  char *c;
};

static struct runInfo ri;

int setup(void) {
  x = mmap(NULL, sizeof *x, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,
           -1, 0);
  y = mmap(NULL, sizeof *y, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,
           -1, 0);
  c = mmap(NULL, sizeof *c, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,
           -1, 0);

  ri.x = x;
  ri.y = y;
  ri.c = c;

  *x = 1;
  *y = 2;
  *c = 't';

  return 0;
}

#endif /* runinfostruct  */
