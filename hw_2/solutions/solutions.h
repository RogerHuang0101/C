#ifndef SOLUTIONS_H
#define SOLUTIONS_H

/*! @file */

/*
the running total function takes an input integer a to calculate the sum
*/
int running_total ( int a );

/*
the reverse function takes an input integer array x and its length to output a new reverse array
*/
int * reverse ( const int * x, int length );

/*
the reverse_in_place function takes an input integer array x and its length to reverse itself
*/
void reverse_in_place(int * x, int length);

/*
the num_occurences function takes an input integer array x and its length and the value to find to check the occurences
*/
int num_occurences(int * x, int length, int value);

#endif