#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <ctype.h>

#include <iostream>
using namespace std;


unsigned int factorial (unsigned int n)
{
  unsigned int fact = 1;
  for (unsigned int i=1; i<n+1; i++)
    fact *= i;
  return fact;
}

int main(int argc, char* argv[])
{
  if (argc != 2)
    {
    puts("Usage: getstring size");
    puts("       where size is the dimension of the buffer");
    return EXIT_FAILURE;
    }
  const unsigned int arg1len = strlen(argv[1]);
  for (unsigned int i=0; i<arg1len; i++)
    {
      if (!isdigit(argv[1][i]))
      {
      cout<<"ERROR: parameter "<<argv[1]<<" is not a positive integer"<<endl;
      return EXIT_FAILURE;
      }
    }
  const unsigned int n = atoi(argv[1]);
  unsigned int res = factorial(n);
  cout << "Factorial: " << n << "! = " << res << endl;
  return EXIT_SUCCESS;
}
