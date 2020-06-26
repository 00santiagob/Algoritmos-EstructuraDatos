#ifndef _SEARCH_H
#define _SEARCH_H

static unsigned int linear_search(int a[], unsigned int length, int x);
/*
    Search in the array 'a' the position of a value x.
    The array 'a' must have exactly 'length' elements.
*/

static unsigned int binary_search(int a[], unsigned int length, int x);
/*
    Search in the array 'a' the position of a value x.
    The array 'a' must have exactly 'length' elements.
*/

static unsigned int binary_search_rec(int a[], int x, unsigned int izq,
                             unsigned int der);
/*
    Search in the array 'a' the position of a value x.
    The array 'a' must have exactly 'length' elements.
    Then the limits are izq = 0 and der = length.
*/

#endif