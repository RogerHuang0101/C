#include "complex.h"
#include <math.h>

Complex add ( Complex a, Complex b ) {
  return (Complex) { a.real + b.real , a.imaginary + b.imaginary };
}

Complex negate ( Complex a) {
  return (Complex) { (-1) * a.real , (-1) * a.imaginary };
}

Complex multiply ( Complex a, Complex b ) {
  return (Complex) { a.real * b.real - a.imaginary * b.imaginary, a.real * b.imaginary + b.real * a.imaginary };
}

double magnitude ( Complex a ) {
  return sqrt(( a.real * a.real )+( a.imaginary * a.imaginary ));
}
