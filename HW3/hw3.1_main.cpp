#include <stdlib.h>
#include <stdio.h>
#include <hw3.1.h>

#include <MyPotential.h>
#include <MyCosine.h>

int main(int argc, char* argv[])
{
  MyPotential mypotential;
  MyCosine mycosine;
  const double x = 1.54;
  const double dfdr = firstDerivative(mypotential, x);
  printf("derivative: %1.17e at: %1.17e\n", dfdr, x);
  const double dfdrc = firstDerivative(mycosine, M_PI/2);
  printf("derivative: %1.17e at: %1.17e\n", dfdrc, M_PI/2);
  const double dfdrc2 = firstDerivative(mycosine, 0.e+00);
  printf("derivative: %1.17e at: %1.17e\n", dfdrc2, 0.e+00);
  return EXIT_SUCCESS;
}
