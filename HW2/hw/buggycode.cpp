
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>

struct header
{
  header* next;
  header* previous;
  uint64_t size;
};

class allocator
{
public:
  allocator();
  ~allocator();
  void* allocate(uint64_t size);
  void release(void*);
private:
  header head;
};

allocator::allocator() : head({NULL, NULL, 0})
{
}

allocator::~allocator()
{
  header* buffer = head.next;
  while (buffer)
    {
    header* nextbuffer = buffer->next;
    release((char*) buffer + sizeof(header));
    buffer = nextbuffer;
    }
}

void
allocator::release(void* mem)
{
  header* buffer = (header*)((char*) mem - sizeof(header));
  uint64_t memsize = buffer->size;
  buffer->previous->next = buffer->next;
  if (buffer->next) buffer->next->previous = buffer->previous;
  munmap(buffer, memsize);
}

void*
allocator::allocate(uint64_t size)
{
  const uint64_t offbits = 4095UL;
  const size_t allocSize = (size+sizeof(header)+offbits) & (~offbits);
  header* buffer = (header*) mmap(NULL, allocSize, PROT_READ|PROT_WRITE,
				  MAP_PRIVATE|MAP_ANONYMOUS , -1 , 0);
  buffer->next = head.next;
  buffer->previous = &head;
  buffer->size = allocSize;
  head.next = buffer;
  return (char*) buffer+sizeof(header);
}

double mean(const double* array, const uint64_t len)
{
  double mean = 0.d+00;
  for (uint64_t i=0; i<len; i++)
    mean += array[i];
  return mean;
}

allocator* globalAllocator=NULL;

void compute(double* a, double*& b, uint64_t len2)
{
  uint64_t looplen = len2;
  allocator getmem;
  globalAllocator = globalAllocator == NULL ? &getmem : globalAllocator;
  if (b==NULL)
    {
    b = (double*) globalAllocator->allocate(looplen);
    }  
  for (unsigned int j=0; j<looplen; j++)
    b[j] = rand()%2 ? -a[j] : a[j];
}

uint64_t getarrdim()
{
  uint64_t dim1 = rand();
  uint64_t dim2 = rand();
  uint64_t dim3 = rand();
  dim2 *=52;
  return dim2/dim3;
}

void getdata(const char* datafile, double* buffer, uint64_t& len)
{
  int fd = open(datafile, O_RDONLY);
  if (fd == -1)
    {
    printf("ERROR: File cannot open file %s\n", datafile);
    exit(1);  
    }
  read(fd, &len, sizeof(uint64_t));
  read(fd, buffer, len*sizeof(double));
  close(fd);
}


int main(int argc, char* argv[])
{
  srand(222209);
  if (argc < 2)
    {
    printf("Error, data file missing\n");
    exit(1);
    }
  const char* datafile = argv[1];
  uint64_t dlen = 0;
  uint64_t dimarr = getarrdim();
  double arr[dimarr];
  double* ptr1 = NULL;
  getdata(datafile, arr, dlen);
  compute(arr, ptr1, dlen);
  double meanvalue = mean(ptr1, dlen);
  printf("meanvalue %15le\n", meanvalue);
  printf("data sample\n");
  for (unsigned int i=0; i<10; i++)
    printf("%le ", ptr1[i]);
  printf("\n");
  return 0;
}
