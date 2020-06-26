#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; goes_before(j, length-1); j++) {
        if (goes_before(a[j], a[min_pos])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

static unsigned int max_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int max_pos = i;
    for (unsigned int j = i + 1; goes_before(j, length-1); j++) {
        if (!goes_before(a[j], a[max_pos])) {
            max_pos = j;
        }
    }
    return (max_pos);
}

void selection_sort(int a[], unsigned int length, bool order) {
    for (unsigned int i = 0; goes_before(i, length-1); i++) {
        if (!order) {
            unsigned int min_pos = min_pos_from(a, i, length);
            swap(a, i, min_pos);
        }
        else {
            unsigned int max_pos = max_pos_from(a, i, length);
            swap(a, i, max_pos);
        }
    }
}

static void insert(int a[], unsigned int i, bool order) {
    int j = i;
    if (!order) {
        while (goes_before(1, j) && !goes_before(a[j-1], a[j])) {
            swap(a, j-1, j);
            j -= 1;
        }
    }
    else {
        while (goes_before(1, j) && goes_before(a[j-1], a[j])) {
            swap(a, j-1, j);
            j -= 1;
        }
    }
}

void insertion_sort(int a[], unsigned int length, bool order) {
    for (unsigned int i = 1; goes_before(i, length-1); i++) {
        assert(is_sorted(a, i-1, order));
        insert(a, i, order);
    }
}
