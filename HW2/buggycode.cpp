#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <ctype.h>
#include <iostream>

using namespace std;

using namespace std;

char* getstring(char* buffer)
{
  const char* cp = "chem281";
  unsigned int* uip = (unsigned int*) cp;
  srand(*uip);
  unsigned int lindex = 0;
  unsigned char c = 0;
  while (c != 'V')
    {
    c = 33+rand()%93;
    buffer[lindex++] = c;
    }
  buffer[lindex]='\0'; //<===
  return buffer;
}

int main(int argc, char* argv[])
{
  if (argc !=2)
    {
    puts("Usage: getstring size");
    puts("       where size is the dimension of the buffer");
    return EXIT_FAILURE;
    }
  const unsigned int arglen = strlen(argv[1]);
  for (unsigned int i=0; i<arglen; i++)
    {
    if (!isdigit(argv[1][i]))
      {
      cout<<"ERROR: parameter "<<argv[1]<< " is not a positive integer"<<endl;
      return EXIT_FAILURE;
      }
    }
  const unsigned int dim = atoi(argv[1]);
  char* achar = new char[dim];
  char* bchar = new char[dim*2];

  achar = getstring(achar);
  delete[] bchar;
  bchar = new char[30];
  return EXIT_SUCCESS;
}
