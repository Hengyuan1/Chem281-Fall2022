#if !defined HW_3_1_H
#define HW_3_1_H
#include <complex>
#include <cmath>

using namespace std;

class Derivable
{
public:
virtual complex<double> eval(const std::complex<double> coord) = 0;
};

double firstDerivative(Derivable&, const double where);
#endif
