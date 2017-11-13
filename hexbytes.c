#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  static char buf[8192];
  while (fgets(buf, 8192, stdin)) {
    int i=0;
    while (i<strlen(buf)) {
      unsigned int v;
      if (sscanf(&(buf[i]), "%02X", &v) == 1)
	fputc((char)v, stdout);
      i += 2;
    }
    //    fputc('\n', stdout);
  }
}
