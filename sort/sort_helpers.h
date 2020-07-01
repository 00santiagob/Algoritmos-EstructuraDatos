#ifndef _SORT_HELPERS_H
#define _SORT_HELPERS_H

#include <stdbool.h>

void swap(int a[], unsigned int i, unsigned int j);
/*
    Exchanges elements of array 'a' in the given positions 'i' and 'j'
    Array remains the same if the two positions are the same
*/

void swap_ui(unsigned int a[], unsigned int i, unsigned int j);
/*
    Exchanges elements of array 'a' in the given positions 'i' and 'j'
    Array remains the same if the two positions are the same
*/

bool goes_before(int x, int y);
/*
    Abstract total order for sorting algorithms
*/

unsigned int partition(int a[], unsigned int izq, unsigned int der, bool order);
/*
    Permutes elements of a[izq..der] and returns pivot such that:
    - izq <= pivot <= der
    - all elements in a[izq,pivot) 'goes_before' a[pivot]
    - a[pivot] 'goes_before' all the elements in a(pivot,der]
*/

#endif
