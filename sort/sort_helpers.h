#ifndef _SORT_HELPERS_H
#define _SORT_HELPERS_H

#include <stdbool.h>

void swap(int a[], unsigned int i, unsigned int j);
/*
    Exchanges elements of array 'a' in the given positions 'i' and 'j'
    Array remains the same if the two positions are the same
*/

bool goes_before(int x, int y);
/*
    Abstract total order for sorting algorithms
*/

bool is_sorted(int a[], unsigned int length, bool order);
/*
    Checks if the array 'a' is in order.
    If order is false, then is ascending order, otherwise it is descending order.
*/

#endif
