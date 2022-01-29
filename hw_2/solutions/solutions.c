#include <stdio.h>
#include "solutions.h"
#include <math.h>

int running_total ( int a ) {
    static int running_sum = 0;
    running_sum += a;
    return running_sum;
}

int * reverse(const int * x, int length) {
    int * result = (int *) calloc(length, sizeof(int));
    int temp;
    for (int i = 0 ; i < length ; i++ ) {
        result[i] = x[length-i-1];
    }
    
    return result;
}

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

int num_occurences(int * x, int length, int value) {
    int count = 0;
    for (int i = 0; i < length ; i++) {
        if (x[i] == value) {
            count ++;
        }
    }
    return count;
}


