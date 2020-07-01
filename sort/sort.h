#ifndef _SORT_H
#define _SORT_H

#include <stdbool.h>

void selection_sort(int a[], unsigned int length, bool order);
/*
    Sort the array 'a' using the Selection sort algorithm.
    If order is false, then is ascending order, otherwise it is descending order.
    The array 'a' must have exactly 'length' elements.

*/

void insertion_sort(int a[], unsigned int length, bool order);
/*
    Sort the array 'a' using the Insertion sort algorithm.
    If order is false, then is ascending order, otherwise it is descending order.
    The array 'a' must have exactly 'length' elements.

*/

void quick_sort(int a[], unsigned int length, bool order);
/*
    Sort the array 'a' using the Quick sort algorithm.
    If order is false, then is ascending order, otherwise it is descending order.
    The array 'a' must have exactly 'length' elements.

*/

#endif
