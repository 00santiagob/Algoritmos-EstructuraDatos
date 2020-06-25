#ifndef _SORT_H
#define _SORT_H

#include <stdbool.h>

void selection_sort(int a[], unsigned int length);
/*
    Sort the array 'a' using the Selection sort algorithm. The resulting sort
    will be ascending.

    The array 'a' must have exactly 'length' elements.

*/

bool is_sorted(int a[], unsigned int length);
/*
    Checks if the array 'a' is in order.
    Always assume that the order is ascending.
*/

#endif
