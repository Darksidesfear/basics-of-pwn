#include <unistd.h>

//  gcc buffer-overflow.c -o buffer-overflow -fno-stack-protector

int main(int argc, char *argv[]){
  char vuln_buff[100];
  int access = 4321;
  // vulnerable
  gets(vuln_buff);
  if (strlen(vuln_buff) > 100):
    exit(1);
  if (access == 1234){
    setuid(0);
    system("/bin/sh");
  }
  return 0;
}
