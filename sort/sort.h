#ifndef _SORT_H
#define _SORT_H

#include <stdbool.h>

bool is_sorted(int a[], unsigned int length, bool order);
/*
    Checks if the array 'a' is in order.
    
    If the order is ascending, then order is true, otherwise it is false.
*/

void selection_sort(int a[], unsigned int length);
/*
    Sort the array 'a' using the Selection sort algorithm. The resulting sort
    will be ascending.

    The array 'a' must have exactly 'length' elements.

*/

#endif
