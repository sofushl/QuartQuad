#include <termios.h> // For termios, tcgetattr(), tcsetattr()
#include <unistd.h>  // For read()

char getch() {
  struct termios old_attr, new_attr;
  char ch;

  tcgetattr(STDIN_FILENO, &old_attr);
  new_attr = old_attr;

  // Disable canonical mode and echo
  new_attr.c_lflag &=
      ~(ICANON | ECHO);     // ICANON = line buffering; ECHO = echo input
  new_attr.c_cc[VMIN] = 1;  // Read at least 1 character
  new_attr.c_cc[VTIME] = 0; // No timeout

  tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);

  read(STDIN_FILENO, &ch, 1);

  tcsetattr(STDIN_FILENO, TCSANOW, &old_attr);

  return ch;
}
