#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int isHexChar(char c) {
  return strchr("0123456789abcdefABCDEF", c) != NULL;
}

int main(int argc, char *argv[]) {
  static char buf[8192];
  while (fgets(buf, 8192, stdin)) {
    int i=0;
    int done=0;
    while (!done) {
      unsigned int v;
      while (i < strlen(buf) && (!isHexChar(buf[i]) || !strncasecmp(&(buf[i]), "0x", 2))) i++;
      if (sscanf(&(buf[i]), "%02X", &v) == 1)
	fputc((char)v, stdout);
      i += 2;
      if (i > strlen(buf)-2)
	done=1;
    }
    //    fputc('\n', stdout);
  }
  return 0;
}
