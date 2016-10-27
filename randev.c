#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int randev(){
  int fd = open("/dev/random", O_RDONLY);
  int ret;
  read(fd, &ret, 4);
  return ret;
}



int main(){
  umask(0000);
  int arr[10];
  int i;
  printf("Generating random numbers:\n");
  for (i = 0; i < 10; i++) {
    arr[i] = randev();
    printf("random %d: %d\n", i, arr[i]);
  }
  printf("\n");

  printf("Writing numbers to file....\n\n");
  int fd = open("dev2", O_CREAT, 0666);
  int w = write(fd,arr,40);
  close(fd);

  printf("Reading numbers from file...\n\n");
  int fd2 = open("dev2", O_RDONLY);
  int arr2[10];
  int r = read(fd2, arr2, 40);
  close(fd2);
  
  printf("Verification that written values were the same:\n");
  for (i = 0; i < 10; i++)
    printf("random %d: %d\n", i, arr2[i]);
 
  return 0;
}