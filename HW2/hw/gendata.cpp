
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>


void gendata(double* a, uint64_t len)
{
  uint64_t looplen = len;
  double factor = (double) RAND_MAX;
  for (unsigned int k=0; k<looplen; k++)
    a[k] = (double)rand() / factor;
  int fd = open("hwddata", O_CREAT|O_WRONLY, 666);
  write(fd, &len, sizeof(uint64_t));
  write(fd, a, len*sizeof(double));
  return;
}

int main(int argc, char* argv[])
{
  srand(222209);
  uint64_t dim1 = rand();
  uint64_t dim2 = rand();
  uint64_t dim3 = rand();
  dim1 *=52;
  dim2 *=52;
  double arr[dim1/dim3];
  gendata(arr,  dim1/dim3);
  return 0;
}
