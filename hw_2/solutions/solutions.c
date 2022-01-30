#include <stdio.h>
#include "solutions.h"
#include <math.h>

/*
the running total function use a static integer to keep track of the current sum
*/
int running_total ( int a ) {
    static int running_sum = 0;
    running_sum += a;
    return running_sum;
}

/*
the reverse function allocate a new memory for the input array to assign the reverse order of the element into the new array: result
*/
int * reverse(const int * x, int length) {
    int * result = (int *) calloc(length, sizeof(int));
    int temp;
    for (int i = 0 ; i < length ; i++ ) {
        result[i] = x[length-i-1];
    }
    
    return result;
}

/*
the reverse_in_place function do the inplace reverse for the input array
*/
void reverse_in_place(int * x, int length) {
    int temp;
    int start = 0;
    int end = length-1;
    while (start < end)
    {
        temp = x[start];  
        x[start] = x[end];
        x[end] = temp;
        start++;
        end--;
    }  
    
}

/*
the num_occurences function counts the occurences for the certain element in the array
*/
int num_occurences(int * x, int length, int value) {
    int count = 0;
    for (int i = 0; i < length ; i++) {
        if (x[i] == value) {
            count ++;
        }
    }
    return count;
}


