#ifndef COMPLEX_H
#define COMPLEX_H

/*! @file */

/*! \breif Fraction object and method definitions
 *
 *  A fraction object is a struct with a numerator, denoted num, and
 *  a denominator, denoted den. Varions Methods that take fractions and return 
 *  fractions do arithmetical operations on them.
 */
typedef struct {
    int real;
    int imaginary;
} Complex;

/*! Add two complex together
 *  \param a The first summand
 *  \param b The second summand
 */
Complex add ( Complex a, Complex b );

/*! Calculate the negate of a complex number
 *  \param a The first term
 */
Complex negate ( Complex a );

/*! Multiply two complex together (does not reduce)
 *  \param a The first term
 *  \param b The second term
 */
Complex multiply ( Complex a, Complex b );

/*! Calculate the magnitude of a complex number
 *  \param a The first term
 */
double magnitude ( Complex a );

#endif